/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief The main file for an employee leave booking system
 */

#include <iostream>
#include <string>
#include <cstring>

#include "ITS.h"
#include "Employee.h"
#include "Manager.h"
#include "HumanResources.h"
#include "Login.h"

int main()
{
    int option;
    vector<string> details;
    string role;

    Login loginUser;
    Employee emp;

    emp.employeeNumber = loginUser.VerifyEmployee();
    
    if (emp.employeeNumber == 0)
    {
        exit(0);
    }

    details = emp.readData("Data/employee_details.csv", emp.employeeNumber);
    role = details[5];

    int manager_status = emp.isManager(emp.employeeNumber);

    if (manager_status == 1)
    {
        role += " Manager";
    }
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

            if (!strcasecmp(role.c_str(), "IT"))
            {
                ITS it;
            }
            else if (!strcasecmp(role.c_str(), "HR"))
            {
                HumanResources HR;
            }
            else if (!strcasecmp(role.c_str(), "Employee Manager"))
            {
                Manager manager;
                break;
            }
            else if (!strcasecmp(role.c_str(), "IT Manager"))
            {
                int option;
                cout << "\n----- More Options ----" << endl;
                cout << "(1) IT Menu";
                cout << "\n(2) Manager Menu";
                cin >> option;

                if (option == 1)
                {
                    ITS it;
                }
                else if (option == 2)
                {
                    Manager manager;
                }
                else
                {
                    cout << "Enter a valid number" << endl;
                }
            }
            else if (!strcasecmp(role.c_str(), "HR Manager"))
            {
                int option;
                cout << "\n----- More Options ----" << endl;
                cout << "(1) HR Menu";
                cout << "\n(2) Manager Menu";
                cin >> option;

                if (option == 1)
                {
                    HumanResources HR;
                }
                else if (option == 2)
                {
                    Manager manager;
                }
                else
                {
                    cout << "Enter a valid number" << endl;
                }
            }
            else
            {
                cout << "No more options to show" << endl;
            }

        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}