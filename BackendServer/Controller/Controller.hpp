#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "PostManager.hpp"
#include "UserManager.hpp"
#include "CommentManager.hpp"
#include <iostream>

class Controller
{
public:
    Controller();
    ~Controller() = default;

    boost::property_tree::ptree addPost(boost::property_tree::ptree &params);
    boost::property_tree::ptree addUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree deletePost(boost::property_tree::ptree &params);
    boost::property_tree::ptree deleteUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree getPost(boost::property_tree::ptree &params);
    boost::property_tree::ptree getTopPosts(boost::property_tree::ptree &params);
    boost::property_tree::ptree getUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree getUserPosts(boost::property_tree::ptree &params);
    boost::property_tree::ptree updatePostRating(boost::property_tree::ptree &params);
    boost::property_tree::ptree addComment(boost::property_tree::ptree &params);
    boost::property_tree::ptree deleteComment(boost::property_tree::ptree &params);

private:
    std::shared_ptr<UserManager> userManager;
    std::shared_ptr<PostManager> postManager;
    std::shared_ptr<CommentManager> commentManager;
};

#endif