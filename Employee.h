/**
 * @file Employee.h
 * @author your name (you@domain.com)
 * @brief
 *
 */

#ifndef Employee_H
#define Employee_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Employee
{
private:
    string employeeFirstName;
    string employeeSurname;
    string employeeEmail;
    int employeeNumber;
    string employeeGender;
    int employeeAge;

public:
    void getPersonalDetails();
    void changePersonalInformation();
    void requestLeave();
    void viewLeave();
    void changeLeave();
    void changePassword();
};

#endif