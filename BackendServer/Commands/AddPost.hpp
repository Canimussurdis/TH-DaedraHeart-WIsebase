#ifndef ADDPOST_HPP
#define ADDPOST_HPP

#include "BaseCommand.hpp"

class AddPost : public BaseCommand
{
public:
    explicit AddPost(boost::property_tree::ptree &params);
    ~AddPost() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif