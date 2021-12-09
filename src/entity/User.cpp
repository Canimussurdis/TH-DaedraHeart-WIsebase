
#include "User.h"
#include "Comment.h"
#include "Post.h"
#include "Tag.h"
#include "../auth/Token.h"

#include <Wt/Dbo/Impl.h>

DBO_INSTANTIATE_TEMPLATES(User);

User::User()
  : role(Visitor),
    failedLoginAttempts(0)
{ }

Posts User::latestPosts(int count) const
{
  return posts.find().where("state = ?").bind(Post::Published)
    .orderBy("date desc")
    .limit(count);
}

Posts User::allPosts(Post::State state) const
{
  return posts.find().where("state = ?").bind(state)
    .orderBy("date desc");
}
