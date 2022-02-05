/**
 * @file ITS.h
 * @author your name (you@domain.com)
 * @brief
 */

#ifndef ITS_H
#define ITS_H

#include <iostream>
#include <string>

#include "Employee.h"

class ITS : public Employee
{
public:
    void addUser();
    void removeUser();
};

#endif
