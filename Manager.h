//
// Created by Scott Tomlins on 26/02/2022.
//

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Employee.h"

using namespace std;

class Manager : public Employee
{
public:
    Manager();
    void reviewLeave();
    void viewUpcomingLeave();

private:
    string userFirstName;
    string userSurname;
    string userEmail;
    string userRole;
    int userEmployeeNumber;
    int userManager;

};

#endif //WM361_CW_MANAGER_H
