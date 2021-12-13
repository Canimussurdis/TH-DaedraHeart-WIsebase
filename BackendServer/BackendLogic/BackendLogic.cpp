#include "BackendLogic.hpp"

BackendLogic::BackendLogic() : controller(new Controller())
{
}

boost::property_tree::ptree BackendLogic::executeCommand(std::shared_ptr<BaseCommand> command)
{
    return command->execute(controller);
}