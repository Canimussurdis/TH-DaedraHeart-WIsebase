#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include "BackendLogic.hpp"
#include "CommandCreator.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>
#include <iostream>
#include <string>

class CommandHandler
{
public:
    CommandHandler();
    ~CommandHandler() = default;

    void runRequest(Wt::Http::Request &request, Wt::Http::Response &response);

private:
    CommandCreator commandCreator;
    BackendLogic backendLogic;
};

#endif