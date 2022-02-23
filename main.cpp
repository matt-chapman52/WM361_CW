/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 */

#include <iostream>

#include "ITS.h"
#include "Employee.h"
#include "Login.h"

int main()
{
    int option;
    // ITS it;
    //Login loginUser;
    Employee emp;

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
            emp.requestLeave();
            break;
        case 4:
            emp.viewLeave();
            break;
        case 5:
            emp.changeLeave();
            break;
            // Case 6 to do, get the job role and show options
        // case 6:
        // if statement;
        // break;
        case 7:
            exit(0);
        }
    }

    // emp.getPersonalDetails();
    // emp.changePersonalDetails();

    return 0;
}