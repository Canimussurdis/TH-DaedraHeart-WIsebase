#ifndef COMMENTMANAGER_HPP
#define COMMENTMANAGER_HPP

#include "BaseManager.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class CommentManager : public BaseManager
{
public:
    ~CommentManager() override = default;

    boost::property_tree::ptree addComment(boost::property_tree::ptree &params);
    boost::property_tree::ptree deleteComment(boost::property_tree::ptree &params);
};

#endif