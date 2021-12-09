#ifndef UPDATEPOSTRATING_HPP
#define UPDATEPOSTRATING_HPP

#include "BaseCommand.hpp"

class UpdatePostRating : public BaseCommand
{
public:
    explicit UpdatePostRating(boost::property_tree::ptree &params);
    ~UpdatePostRating() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif