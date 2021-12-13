#ifndef COMMANDCREATOR_HPP
#define COMMANDCREATOR_HPP

#include "AddPost.hpp"
#include "AddUser.hpp"
#include "DeletePost.hpp"
#include "DeleteUser.hpp"
#include "GetPost.hpp"
#include "GetTopPosts.hpp"
#include "GetUser.hpp"
#include "GetUserPosts.hpp"
#include "UpdatePostRating.hpp"
#include "AddComment.hpp"
#include "DeleteComment.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class CommandCreator
{
public:
    std::shared_ptr<BaseCommand> createCommand(std::string method, std::string path, boost::property_tree::ptree &body);
};

#endif