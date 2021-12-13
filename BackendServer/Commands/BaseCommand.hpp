#ifndef BASECOMMAND_HPP
#define BASECOMMAND_HPP

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>

#include "Controller.hpp"

class BaseCommand
{
public:
    BaseCommand(const std::string &name) : name(name){};
    virtual ~BaseCommand() = default;

    virtual boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) = 0;

public:
    boost::property_tree::ptree commandParams;
    std::string name;
};
#endif