#include "DeleteComment.hpp"

DeleteComment::DeleteComment(boost::property_tree::ptree &params) : BaseCommand("DeleteComment") {
    commandParams = params;
}

boost::property_tree::ptree DeleteComment::execute(std::shared_ptr<Controller> controller) {
    return controller->deleteComment(commandParams);
}