#include "AddComment.hpp"

AddComment::AddComment(boost::property_tree::ptree &params) : BaseCommand("AddComment") {
    commandParams = params;
}

boost::property_tree::ptree AddComment::execute(std::shared_ptr<Controller> controller) {
    return controller->addComment(commandParams);
}