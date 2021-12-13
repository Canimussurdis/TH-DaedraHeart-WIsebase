#ifndef BACKENDLOGIC_HPP
#define BACKENDLOGIC_HPP

#include "BaseCommand.hpp"
#include "Controller.hpp"

class BackendLogic
{
public:
    BackendLogic();
    boost::property_tree::ptree executeCommand(std::shared_ptr<BaseCommand> command);

private:
    std::shared_ptr<Controller> controller;
};

#endif