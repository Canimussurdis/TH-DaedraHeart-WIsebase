#ifndef ADDUSER_HPP
#define ADDUSER_HPP

#include "BaseCommand.hpp"

class AddUser : public BaseCommand
{
public:
    explicit AddUser(boost::property_tree::ptree &params);
    ~AddUser() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif