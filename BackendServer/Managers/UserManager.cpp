#include "UserManager.hpp"

boost::property_tree::ptree UserManager::addUser(boost::property_tree::ptree &params) {
    DataBaseConnection dbConnector;
    dbConnector.AddUser(params);
    return params;
}

boost::property_tree::ptree UserManager::deleteUser(boost::property_tree::ptree &params) {
    DataBaseConnection dbConnector;
    dbConnector.DeleteUser(params);
    return params;
}


boost::property_tree::ptree UserManager::getUser(boost::property_tree::ptree &params) {
    DataBaseConnection dbConnector;
    dbConnector.GetUser(params);
    return params;
}