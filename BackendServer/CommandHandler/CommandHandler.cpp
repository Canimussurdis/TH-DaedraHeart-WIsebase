#include "CommandHandler.hpp"
#include "DataBaseConnection.hpp"

CommandHandler::CommandHandler() : commandCreator(), backendLogic() {}

void CommandHandler::runRequest(Wt::Http::Request &request, Wt::Http::Response &response)
{
    std::string method = request.method();
    std::string path = request.path();

    boost::property_tree::ptree body;
    boost::property_tree::read_json(request.in(), body);

    std::shared_ptr<BaseCommand> command = commandCreator.createCommand(method, path, body);

    DataBaseConnection dbConnector();

    boost::property_tree::ptree result = backendLogic.executeCommand(command);
    std::string command_name = result.get<std::string>("command");

    std::stringstream result_stream;
    boost::property_tree::json_parser::write_json(result_stream, result);
    std::string response_body = result_stream.str();

    response.setStatus(200);
    response.setMimeType("application/json");

    response.out() << response_body;
}