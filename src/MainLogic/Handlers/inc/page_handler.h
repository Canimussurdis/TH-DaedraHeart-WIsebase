#ifndef PAGE_HANDLER_H
#define PAGE_HANDLER_H

#include "base_handler.h"

class PageHandler: public BaseHandler{
public:
    PageHandler(const Request &request) : BaseHandler(request) {};
    ~PageHandler() override = default;

    Response execute() override;

public:
    Request request;
};

#endif