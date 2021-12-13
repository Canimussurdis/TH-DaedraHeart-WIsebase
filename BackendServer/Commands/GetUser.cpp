#include "GetUser.hpp"

GetUser::GetUser(boost::property_tree::ptree &params) : BaseCommand("GetUser") {
    commandParams = params;
}

boost::property_tree::ptree GetUser::execute(std::shared_ptr<Controller> controller) {
    return controller->getUser(commandParams);
}