#include "GetTopPosts.hpp"

GetTopPosts::GetTopPosts(boost::property_tree::ptree &params) : BaseCommand("GetTopPosts") {
    commandParams = params;
}

boost::property_tree::ptree GetTopPosts::execute(std::shared_ptr<Controller> controller) {
    return controller->getTopPosts(commandParams);
}