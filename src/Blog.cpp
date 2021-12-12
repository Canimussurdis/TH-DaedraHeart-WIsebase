
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WServer.h>
#include <Wt/Dbo/SqlConnectionPool.h>
#include <Wt/Dbo/FixedSqlConnectionPool.h>
#include <Wt/Dbo/backend/Sqlite3.h>

#include "BlogSession.h"
#include "auth/Token.h"
#include "entity/User.h"
#include "BlogView.h"
#include "BlogRSSFeed.h"
//#include "BackendServer/CommandHandler/CommandHandler.hpp"

//#include "0/WServer.h" // a slightly customized version of WServer

/*using std::cerr;
using std::endl;
//using boost::bind;

using Wt::WApplication;
using Wt::WEnvironment;
using Wt::WApplication;
//using Wt::Application;
//using Wt::WServer;
using Ma::WServer;

typedef Wt::Dbo::SqlConnectionPool Database; // just for simplicity
namespace dbo = Wt::Dbo;

static const char *FEEDURL = "/blog/feed/";
static const char *BLOGURL = "/blog";

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

class BlogApplication : public WApplication
{
public:
  BlogApplication(const WEnvironment& env) : WApplication(env)
  {
    root()->addWidget(std::make_unique<BlogView>("/", *db_, FEEDURL));
    useStyleSheet("css/blogexample.css");
  }

  // use a static method for any general/global resource allocation/initialization
  static void init(const std::string& sqliteDb)
  {
    BlogSession::configureAuth();

    auto connection = std::make_unique<dbo::backend::Sqlite3>(sqliteDb);

    connection->setProperty("show-queries", "true");
    //connection->setDateTimeStorage(Wt::Dbo::SqlDateTime, dbo::backend::Sqlite3::PseudoISO8601AsText);

    // keep the db available to the class
    db_ = new Wt::Dbo::FixedSqlConnectionPool(std::move(connection), 10);
  }

  // used by the server to create instances for each user
  static std::unique_ptr<Wt::WApplication> create(const WEnvironment& env)
  {
    return std::make_unique<BlogApplication>(env);
  }

  static dbo::FixedSqlConnectionPool* db() {return db_;}
  static void free() {delete db_;}

private:
  static dbo::FixedSqlConnectionPool* db_;

};

dbo::FixedSqlConnectionPool* BlogApplication::db_; // storage for private class variable

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char **argv)
{
  try {
    WServer server(argc, argv, "./wthttpd");

    BlogApplication::init(server.appRoot() + "blog.db");
    server.addApplication(&BlogApplication::create, BLOGURL);

    BlogRSSFeed rssFeed(*BlogApplication::db(), "Wt blog example", "", "It's just an example.");
    server.addResource(&rssFeed, FEEDURL);

    server.run();

    BlogApplication::free();
  }
  catch (WServer::Exception& e) {
    cerr << e.what() << endl;
  }
  catch (std::exception &e) {
    cerr << "exception: " << e.what() << endl;
  }
}
*/

static const char* FeedUrl = "/blog/feed/";
static const char* BlogUrl = "/blog";

class BlogApplication : public Wt::WApplication
{
public:
    BlogApplication(const Wt::WEnvironment& env, Wt::Dbo::SqlConnectionPool& blogDb)
        : Wt::WApplication(env)
    {
        root()->addWidget(std::make_unique<BlogView>("/", blogDb, FeedUrl));
        useStyleSheet("css/blogexample.css");
    }
};

std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env,
    Wt::Dbo::SqlConnectionPool* blogDb)
{
    return std::make_unique<BlogApplication>(env, *blogDb);
}

int main(int argc, char** argv)
{
    try {
        Wt::WServer server(argc, argv, WTHTTP_CONFIGURATION);

        BlogSession::configureAuth(); // верификация данных пользователя для входа

        std::unique_ptr<Wt::Dbo::SqlConnectionPool> blogDb = BlogSession::createConnectionPool(server.appRoot() + "blog.db"); 

        //std::unique_ptr<Wt::Http::Response> blogDb = CommandHandler::runRequest(server.appRoot());

        //CommandHandler rssFeed(const Wt::Http::Request & request, Wt::Http::Response & response);

        BlogRSSFeed rssFeed(*blogDb, "Wt blog example", "", "It's just an example.");

        server.addResource(&rssFeed, FeedUrl);
        
        server.addEntryPoint(Wt::EntryPointType::Application, std::bind(&createApplication, std::placeholders::_1, blogDb.get()), BlogUrl);

        std::cerr << "\n\n -- Warning: Example is deployed at '"
            << BlogUrl << "'\n\n";

        server.run();

    }
    catch (Wt::WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}


