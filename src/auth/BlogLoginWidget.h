
#ifndef BLOG_LOGIN_WIDGET_H_
#define BLOG_LOGIN_WIDGET_H_

#include <Wt/Auth/AuthWidget.h>

class BlogSession;

/*
 * Displays login, logout and registration options
 */
class BlogLoginWidget : public Wt::Auth::AuthWidget
{
public:
  BlogLoginWidget(BlogSession& session, const std::string& basePath);

  virtual void createLoginView();
  virtual void createLoggedInView();
};

#endif // BLOG_LOGIN_WIDGET_H_
