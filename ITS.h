/**
 * @file ITS.h
 * @author your name (you@domain.com)
 * @brief
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
    void showOptions();
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
