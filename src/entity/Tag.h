
#ifndef TAG_H_
#define TAG_H_

#include <Wt/Dbo/Types.h>

class Post;

namespace dbo = Wt::Dbo;

typedef dbo::collection< dbo::ptr<Post> > Posts;

class Tag {
public:
  Tag() { }
  Tag(const std::string& aName)
    : name(aName) { }

  std::string name;

  Posts       posts;

  template<class Action>
  void persist(Action& a)
  {
    dbo::field(a, name, "name");

    dbo::hasMany(a, posts, dbo::ManyToMany, "post_tag");
  }
};

DBO_EXTERN_TEMPLATES(Tag);

#endif // TAG_H_
