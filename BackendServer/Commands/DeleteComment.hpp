#ifndef DELETECOMMENT_HPP
#define DELETECOMMENT_HPP

#include "BaseCommand.hpp"

class DeleteComment : public BaseCommand
{
public:
    explicit DeleteComment(boost::property_tree::ptree &params);
    ~DeleteComment() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif