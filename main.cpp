/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 */

#include <iostream>

#include "ITS.h"
#include "Employee.h"
#include "HumanResources.h"
#include "Login.h"

int main()
{
    int option;
    vector<string> details;
    string role;

    Login loginUser;
    Employee employee;
    HumanResources HR;
    // Manager manager;

    int empNum = loginUser.VerifyEmployee();

    Employee emp;

    details = emp.readData("Data/employee_details.csv", empNum);
    role = details[5];

    cout << role << endl;

    while (true)
    {
        option = emp.showOptions();
        switch (option)
        {
        case 1:
            emp.getPersonalDetails();
            break;
        case 2:
            emp.changePersonalDetails();
            break;
        case 3:
            emp.viewLeave();
            break;
        case 4:
            if (!strcasecmp(role.c_str(), "Employee"))
            {
                cout << "No more options to show" << endl;
            }
            else if (!strcasecmp(role.c_str(), "IT"))
            {
                ITS it;
            }
            else if (!strcasecmp(role.c_str(), "HR"))
            {
                HumanResources HR;
            }
            else if (!strcasecmp(role.c_str(), "Manager"))
            {
                // Manager manager;
                // manager.showoptions();
            }

        case 5:
            exit(0);
            break;
        }
    }

    // emp.getPersonalDetails();
    // emp.changePersonalDetails();

    return 0;
}