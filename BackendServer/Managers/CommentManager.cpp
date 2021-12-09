#include "CommentManager.hpp"

boost::property_tree::ptree CommentManager::addComment(boost::property_tree::ptree &params)
{
    dbConnector.AddComment(params);
    return params;
}

boost::property_tree::ptree CommentManager::deleteComment(boost::property_tree::ptree &params)
{
    dbConnector.DeleteComment(params);
    return params;
}