#include "DeletePost.hpp"

DeletePost::DeletePost(boost::property_tree::ptree &params) : BaseCommand("DeleteGrade") {
    commandParams = params;
}

boost::property_tree::ptree DeletePost::execute(std::shared_ptr<Controller> controller) {
    return controller->deletePost(commandParams);
}