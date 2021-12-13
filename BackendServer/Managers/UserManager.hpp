#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include "BaseManager.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class UserManager : public BaseManager
{
public:
    ~UserManager() override = default;

    boost::property_tree::ptree addUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree deleteUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree getUser(boost::property_tree::ptree &params);
};

#endif