/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 */

#include <iostream>

#include "ITS.h"
#include "Employee.h"

int main()
{
    int option;
    // ITS it;
    Employee emp;
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
    }

    // emp.getPersonalDetails();
    // emp.changePersonalDetails();

    return 0;
}