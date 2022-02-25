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

            if (!strcasecmp(role.c_str(), "IT"))
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
                    // Manager manager;
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
                    // Manager manager;
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

    // emp.getPersonalDetails();
    // emp.changePersonalDetails();

    return 0;
}