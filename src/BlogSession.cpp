

#include "BlogSession.h"
#include "entity/Comment.h"
#include "entity/Post.h"
#include "entity/Tag.h"
#include "auth/Token.h"
#include "entity/User.h"
#include "asciidoc/asciidoc.h"

#include <Wt/Auth/AuthService.h>
#include <Wt/Auth/HashFunction.h>
#include <Wt/Auth/Identity.h>
#include <Wt/Auth/PasswordService.h>
#include <Wt/Auth/PasswordStrengthValidator.h>
#include <Wt/Auth/PasswordVerifier.h>
#include <Wt/Auth/GoogleService.h>
#include <Wt/Dbo/backend/Postgres.h>


#include <Wt/Dbo/FixedSqlConnectionPool.h>

#ifndef WIN32
#include <unistd.h>
#endif

#if !defined(WIN32) && !defined(__CYGWIN__) && !defined(ANDROID)
#define HAVE_CRYPT
#endif

using namespace Wt;

namespace {
  const std::string ADMIN_USERNAME = "admin";
  const std::string ADMIN_PASSWORD = "admin";

#ifdef HAVE_CRYPT
  class UnixCryptHashFunction : public Auth::HashFunction
  {
  public:
    virtual std::string compute(const std::string& msg, 
				const std::string& salt) const
    {
      std::string md5Salt = "$1$" + salt;
      return crypt(msg.c_str(), md5Salt.c_str());
    }

    virtual bool verify(const std::string& msg,
			const std::string& salt,
			const std::string& hash) const
    {
      return crypt(msg.c_str(), hash.c_str()) == hash;
    }

    virtual std::string name () const {
      return "crypt";
    }
  };
#endif // HAVE_CRYPT

  class BlogOAuth : public std::vector<const Auth::OAuthService *>
  {
  public:
    ~BlogOAuth()
    {
      for (unsigned i = 0; i < size(); ++i)
	delete (*this)[i];
    }
  };

  Auth::AuthService blogAuth;
  Auth::PasswordService blogPasswords(blogAuth);
  BlogOAuth blogOAuth;
}

namespace dbo = Wt::Dbo;

void BlogSession::configureAuth() // верификация 
{
  blogAuth.setAuthTokensEnabled(true, "bloglogin");

  std::unique_ptr<Wt::Auth::PasswordVerifier> verifier = std::make_unique<Wt::Auth::PasswordVerifier>();
  verifier->addHashFunction(std::make_unique<Wt::Auth::BCryptHashFunction>(7));
#ifdef WT_WITH_SSL
  verifier->addHashFunction(std::make_unique<Wt::Auth::SHA1HashFunction>());
#endif
#ifdef HAVE_CRYPT
  verifier->addHashFunction(new UnixCryptHashFunction());
#endif
  blogPasswords.setVerifier(std::move(verifier));
  blogPasswords.setAttemptThrottlingEnabled(true);
  blogPasswords.setStrengthValidator
    (std::make_unique<Wt::Auth::PasswordStrengthValidator>());

  if (Auth::GoogleService::configured())
    blogOAuth.push_back(new Auth::GoogleService(blogAuth));
}

std::unique_ptr<dbo::SqlConnectionPool> BlogSession::createConnectionPool(const std::string& sqliteDb) // подключение к базе данных 
{
    auto connection = std::make_unique<dbo::backend::Sqlite3>(sqliteDb);
    // auto connection = std::make_unique<Wt:Http:Response>(postgresDb);

    connection->setProperty("show-queries", "true");
    connection->setDateTimeStorage(Wt::Dbo::SqlDateTimeType::DateTime, Wt::Dbo::backend::DateTimeStorage::PseudoISO8601AsText);

    return std::make_unique<Wt::Dbo::FixedSqlConnectionPool>(std::move(connection), 10);
}

BlogSession::BlogSession(dbo::SqlConnectionPool& connectionPool) // сесия пользователя - работа с бд
  : connectionPool_(connectionPool),
    users_(*this)
{
  setConnectionPool(connectionPool_);

  mapClass<Comment>("comment");
  mapClass<Post>("post");
  mapClass<Tag>("tag");
  mapClass<Token>("token");
  mapClass<User>("user");

  try {
    dbo::Transaction t(*this);
    createTables();

    dbo::ptr<User> admin = add(std::make_unique<User>());
    User *a = admin.modify();
    a->name = ADMIN_USERNAME;
    a->role = User::Admin;

    Auth::User authAdmin
      = users_.findWithIdentity(Auth::Identity::LoginName, a->name);
    blogPasswords.updatePassword(authAdmin, ADMIN_PASSWORD);

    dbo::ptr<Post> post = add(std::make_unique<Post>());
    Post *p = post.modify();

    p->state = Post::Published;
    p->author = admin;
    p->title = "Welcome!";
    p->briefSrc = "Welcome to your own blog.";
    p->bodySrc = "We have created for you an " + ADMIN_USERNAME +
      " user with password " + ADMIN_PASSWORD;
    p->briefHtml = asciidoc(p->briefSrc); // неккоректно работает функция аскидок!
    p->bodyHtml = asciidoc(p->bodySrc);
    p->date = WDateTime::currentDateTime();

    dbo::ptr<Comment> rootComment = add(std::make_unique<Comment>());
    rootComment.modify()->post = post;

    t.commit();

    std::cerr << "Created database, and user " << ADMIN_USERNAME
	      << " / " << ADMIN_PASSWORD << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::cerr << "Using existing database";
  }
}

dbo::ptr<User> BlogSession::user() const
{
  if (login_.loggedIn())
    return users_.find(login_.user());
  else
    return dbo::ptr<User>();
}

Auth::PasswordService *BlogSession::passwordAuth() const
{
  return &blogPasswords;
}

const std::vector<const Auth::OAuthService *>& BlogSession::oAuth() const
{
  return blogOAuth;
}
