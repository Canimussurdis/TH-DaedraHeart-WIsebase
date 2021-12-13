#include "UpdatePostRating.hpp"

UpdatePostRating::UpdatePostRating(boost::property_tree::ptree &params) : BaseCommand("UpdatePostRating") {
    commandParams = params;
}

boost::property_tree::ptree UpdatePostRating::execute(std::shared_ptr<Controller> controller) {
    return controller->updatePostRating(commandParams);
}