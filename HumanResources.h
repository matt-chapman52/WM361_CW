/**
 * @file HumanResources.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HumanResources_H
#define HumanResources_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Employee.h"

using namespace std;

class HumanResources : public Employee
{
public:
    HumanResources();
    void changeManager();

private:
    int tempEmpNum;
    int empNum;
    int newManager;
};

#endif