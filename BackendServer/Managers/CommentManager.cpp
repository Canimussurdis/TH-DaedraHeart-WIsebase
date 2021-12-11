#include "CommentManager.hpp"

boost::property_tree::ptree CommentManager::addComment(boost::property_tree::ptree &params)
{
    DataBaseConnection dbConnector;
    dbConnector.AddComment(params);
    return params;
}

boost::property_tree::ptree CommentManager::deleteComment(boost::property_tree::ptree &params)
{
    DataBaseConnection dbConnector;
    dbConnector.DeleteComment(params);
    return params;
}