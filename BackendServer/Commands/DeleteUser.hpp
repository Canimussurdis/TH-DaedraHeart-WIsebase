#ifndef DELETEUSER_HPP
#define DELETEUSER_HPP

#include "BaseCommand.hpp"

class DeleteUser : public BaseCommand
{
public:
    explicit DeleteUser(boost::property_tree::ptree &params);
    ~DeleteUser() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif