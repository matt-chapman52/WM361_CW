/**
 * @file ITS.h
 * @author 1943001
 * @brief IT header file containing declarations realting to ITS.cpp
 */

#ifndef ITS_H
#define ITS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Employee.h"

using namespace std;

class ITS : public Employee
{
public:
    ITS();
    void addUser();
    void removeUser();

private:
    string userFirstName;
    string userSurname;
    string userEmail;
    string userRole;
    int userEmployeeNumber;
    int userManager;
};

#endif
