#ifndef BASEMANAGER_H
#define BASEMANAGER_H

#include "DataBaseConnection.hpp"

class BaseManager {
public:
    BaseManager();
    virtual ~BaseManager() = default;

protected:
    DataBaseConnection dbConnector;
};


#endif