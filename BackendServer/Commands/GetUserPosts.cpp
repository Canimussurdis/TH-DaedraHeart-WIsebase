#include "GetUserPosts.hpp"

GetUserPosts::GetUserPosts(boost::property_tree::ptree &params) : BaseCommand("GetUserPosts") {
    commandParams = params;
}

boost::property_tree::ptree GetUserPosts::execute(std::shared_ptr<Controller> controller) {
    return controller->getUserPosts(commandParams);
}