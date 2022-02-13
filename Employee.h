/**
 * @file Employee.h
 * @author your name (you@domain.com)
 * @brief
 *
 */

#ifndef Employee_H
#define Employee_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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
    string password;

public:
    Employee();
    void getPersonalDetails();
    void changePersonalDetails();
    void requestLeave();
    void viewLeave();
    void changeLeave();
};

#endif