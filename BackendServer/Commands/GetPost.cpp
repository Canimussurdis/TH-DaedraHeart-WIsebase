#include "GetPost.hpp"

GetPost::GetPost(boost::property_tree::ptree &params) : BaseCommand("GetPost") {
    commandParams = params;
}

boost::property_tree::ptree GetPost::execute(std::shared_ptr<Controller> controller) {
    return controller->getPost(commandParams);
}