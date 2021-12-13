#ifndef GETPOST_HPP
#define GETPOST_HPP

#include "BaseCommand.hpp"

class GetPost : public BaseCommand
{
public:
    explicit GetPost(boost::property_tree::ptree &params);
    ~GetPost() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif