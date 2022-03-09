/**
 * @file Login.h
 * @author 1942995
 * @brief Login header file containing declarations relating to Login.cpp
 */

#ifndef Login_H
#define Login_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>

#include "Employee.h"

using namespace std;

class Login : public Employee 
{
private:
    bool verifyEmpNum(int loginEmpNum, string dataFile);
    bool reVerifyEmpNum(string dataFile);
    bool verifyPassword(int loginEmpNum);
    bool resetPassword();
    int loginEmployeeNum;
    int empNumRetry;
    int attemptsLeft;
    string loginPassword;
    string databasePassword;
    vector<string> userData;
public:
    int verifyEmployee();
};

#endif
