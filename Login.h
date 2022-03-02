/**
 * @file Login.h
 * @author Jack Pang (u1942995@live.warwick.ac.uk)
 * @brief
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
    bool VerifyEmpNum(int loginEmpNum, string dataFile);
    bool ReVerifyEmpNum(string dataFile);
    bool VerifyPassword(int loginEmpNum);
    bool ResetPassword();
    int loginEmployeeNum;
    int databaseEmployeeNum;
    int empNumRetry;
    int attemptsLeft;
    string loginPassword;
    string databasePassword;
    vector<string> userData;


public:
    int VerifyEmployee();
};

#endif
