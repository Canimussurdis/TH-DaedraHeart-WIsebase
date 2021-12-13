#ifndef POSTMANAGER_HPP
#define POSTMANAGER_HPP

#include "BaseManager.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class PostManager : public BaseManager
{
public:
    ~PostManager() override = default;

    boost::property_tree::ptree addPost(boost::property_tree::ptree &params);
    boost::property_tree::ptree deletePost(boost::property_tree::ptree &params);
    boost::property_tree::ptree getPost(boost::property_tree::ptree &params);
    boost::property_tree::ptree getTopPosts(boost::property_tree::ptree &params);
    boost::property_tree::ptree getUserPosts(boost::property_tree::ptree &params);
    boost::property_tree::ptree updatePostRating(boost::property_tree::ptree &params);
};

#endif