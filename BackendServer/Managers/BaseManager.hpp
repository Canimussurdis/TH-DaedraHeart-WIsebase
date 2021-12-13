#ifndef BASEMANAGER_H
#define BASEMANAGER_H

#include "DataBaseConnection.hpp"
#include <iostream>

class BaseManager {
public:
    explicit BaseManager();
    virtual ~BaseManager() = default;
};
    
#endif