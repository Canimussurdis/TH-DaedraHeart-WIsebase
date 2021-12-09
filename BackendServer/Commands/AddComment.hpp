#ifndef ADDCOMMENT_HPP
#define ADDCOMMENT_HPP

#include "BaseCommand.hpp"

class AddComment : public BaseCommand
{
public:
    explicit AddComment(boost::property_tree::ptree &params);
    ~AddComment() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif