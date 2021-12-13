#ifndef GETUSER_HPP
#define GETUSER_HPP

#include "BaseCommand.hpp"

class GetUser : public BaseCommand
{
public:
    explicit GetUser(boost::property_tree::ptree &params);
    ~GetUser() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif