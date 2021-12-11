#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include "BackendLogic.hpp"
#include "CommandCreator.hpp"
#include "DataBaseConnection.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>
#include <Wt/WResource.h>
#include <iostream>
#include <string>

class CommandHandler: public Wt::WResource
{
public:
    CommandHandler();
    virtual ~CommandHandler() = default;

protected:
    virtual void handleRequest(const Wt::Http::Request &request, Wt::Http::Response &response);

private:
    CommandCreator commandCreator;
    BackendLogic backendLogic;
};

#endif