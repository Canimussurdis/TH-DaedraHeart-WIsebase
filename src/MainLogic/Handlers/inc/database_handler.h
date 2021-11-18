#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include "base_handler.h"

class DatabaseHandler: public BaseHandler{
public:
    DatabaseHandler(const Request &request) : BaseHandler(request) {};
    ~DatabaseHandler() override = default;

    Response execute() override;

public:
    Request request;
};

#endif