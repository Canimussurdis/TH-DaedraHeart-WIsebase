#include "DeleteUser.hpp"

DeleteUser::DeleteUser(boost::property_tree::ptree &params) : BaseCommand("DeleteUser") {
    commandParams = params;
}

boost::property_tree::ptree DeleteUser::execute(std::shared_ptr<Controller> controller) {
    return controller->deleteUser(commandParams);
}