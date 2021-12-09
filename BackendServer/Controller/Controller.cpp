#include "Controller.hpp"
#include <boost/property_tree/ptree.hpp>

Controller::Controller() {}


boost::property_tree::ptree Controller::addPost(boost::property_tree::ptree &params)
{
    return postManager->addPost(params);
}

boost::property_tree::ptree Controller::addUser(boost::property_tree::ptree &params)
{
    return userManager->addUser(params);
}

boost::property_tree::ptree Controller::deletePost(boost::property_tree::ptree &params)
{
    return postManager->deletePost(params);
}

boost::property_tree::ptree Controller::deleteUser(boost::property_tree::ptree &params)
{
    return userManager->deleteUser(params);
}

boost::property_tree::ptree Controller::getPost(boost::property_tree::ptree &params)
{
    return postManager->getPost(params);
}

boost::property_tree::ptree Controller::getTopPosts(boost::property_tree::ptree &params)
{
    return postManager->getTopPosts(params);
}

boost::property_tree::ptree Controller::getUser(boost::property_tree::ptree &params)
{
    return userManager->getUser(params);
}

boost::property_tree::ptree Controller::getUserPosts(boost::property_tree::ptree &params)
{
    return postManager->getUserPosts(params);
}

boost::property_tree::ptree Controller::updatePostRating(boost::property_tree::ptree &params)
{
    return postManager->updatePostRating(params);
}

boost::property_tree::ptree Controller::addComment(boost::property_tree::ptree &params)
{
    return commentManager->addComment(params);
}

boost::property_tree::ptree Controller::deleteComment(boost::property_tree::ptree &params)
{
    return commentManager->deleteComment(params);
}