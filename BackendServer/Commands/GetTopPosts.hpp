#ifndef GETTOPPOSTS_HPP
#define GETTOPPOSTS_HPP

#include "BaseCommand.hpp"

class GetTopPosts : public BaseCommand
{
public:
    explicit GetTopPosts(boost::property_tree::ptree &params);
    ~GetTopPosts() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif