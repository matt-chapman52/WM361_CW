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
using namespace std;

class Employee
{
private:
    string firstName;
    string surname;
    string email;
    int employeeNumber;
    string gender;
    int age;

public:
    void getPersonalDetails();
    void changePersonalDetails();
    void requestLeave();
    void viewLeave();
    void changeLeave();
};

#endif