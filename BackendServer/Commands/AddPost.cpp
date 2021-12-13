#include "AddPost.hpp"

AddPost::AddPost(boost::property_tree::ptree &params) : BaseCommand("AddPost") {
    commandParams = params;
}

boost::property_tree::ptree AddPost::execute(std::shared_ptr<Controller> controller) {
    return controller->addPost(commandParams);
}