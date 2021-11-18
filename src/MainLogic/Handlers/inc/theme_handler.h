#ifndef THEME_HANDLER_H
#define THEME_HANDLER_H

#include "base_handler.h"

class ThemeHandler: public BaseHandler{
public:
    ThemeHandler(const Request &request) : BaseHandler(request) {};
    ~ThemeHandler() override = default;

    Response execute() override;

public:
    Request request;
};

#endif