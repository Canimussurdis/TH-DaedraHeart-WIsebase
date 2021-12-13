#include "CommandHandler.hpp"

CommandHandler::CommandHandler() : commandCreator(), backendLogic() {}

void CommandHandler::handleRequest(const Wt::Http::Request &request, Wt::Http::Response &response)
{
    std::string method = request.method();
    std::string path = request.path();

    std::string temp_body;
    request.in() >> temp_body;

    std::stringstream body_stream;

    body_stream << temp_body;

    boost::property_tree::ptree body;
    boost::property_tree::read_json(temp_body, body);

    std::shared_ptr<BaseCommand> command = commandCreator.createCommand(method, path, body);

    boost::property_tree::ptree result = backendLogic.executeCommand(command);

    std::stringstream result_stream;
    boost::property_tree::json_parser::write_json(result_stream, result);
    std::string response_body = result_stream.str();

    response.setStatus(200);
    response.setMimeType("application/json");

    response.out() << response_body;
}