#ifndef GETUSERPOSTS_HPP
#define GETUSERPOSTS_HPP

#include "BaseCommand.hpp"

class GetUserPosts : public BaseCommand
{
public:
    explicit GetUserPosts(boost::property_tree::ptree &params);
    ~GetUserPosts() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif