#include "UserManager.hpp"

boost::property_tree::ptree UserManager::addUser(boost::property_tree::ptree &params) {
    dbConnector.AddUser(params);
    return params;
}

boost::property_tree::ptree UserManager::deleteUser(boost::property_tree::ptree &params) {
    dbConnector.DeleteUser(params);
    return params;
}


boost::property_tree::ptree UserManager::getUser(boost::property_tree::ptree &params) {
    dbConnector.GetUser(params);
    return params;
}