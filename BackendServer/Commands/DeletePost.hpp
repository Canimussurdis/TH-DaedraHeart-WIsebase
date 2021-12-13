#ifndef DELETEPOST_HPP
#define DELETEPOST_HPP

#include "BaseCommand.hpp"

class DeletePost : public BaseCommand
{
public:
    explicit DeletePost(boost::property_tree::ptree &params);
    ~DeletePost() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif