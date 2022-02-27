/**
 * @file HumanResources.h
 * @author 1943001
 * @brief
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
    void changeJobRole();

private:
    int tempEmpNum;
    int empNum;
    string newManager;
    string newRole;
};

#endif