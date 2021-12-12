
#ifndef BLOG_RSS_FEED_H_
#define BLOG_RSS_FEED_H_

#include <Wt\WResource.h>
#include <Wt/Http/Response.h>
//#include "BackendServer/CommandHandler/CommandHandler.hpp"


class BlogSession;

class BlogRSSFeed : public Wt::WResource
{
	
public:
  BlogRSSFeed(Wt::Dbo::SqlConnectionPool& connectionPool,
	      const std::string& title,
	      const std::string& url,
	      const std::string& description);
  virtual ~BlogRSSFeed();

protected:
  virtual void handleRequest(const Wt::Http::Request& request,
	  Wt::Http::Response& response);

private:
  Wt::Dbo::SqlConnectionPool& connectionPool_;
  std::string title_, url_, description_;
};



class Response : public Wt::Http::Response {
public:
	Wt::Http::Response response;
};


#endif // BLOG_RSS_FEED_H_