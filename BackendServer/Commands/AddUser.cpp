#include "AddUser.hpp"

AddUser::AddUser(boost::property_tree::ptree &params) : BaseCommand("AddUser") {
    commandParams = params;
}

boost::property_tree::ptree AddUser::execute(std::shared_ptr<Controller> controller) {
    return controller->addUser(commandParams);
}