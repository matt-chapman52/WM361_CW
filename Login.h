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

#include "Employee.h"

using namespace std;

class Login : public Employee 
{
private:
    bool VerifyEmpNum(int loginEmpNum, string dataFile);
    bool ReVerifyEmpNum(string dataFile);
    bool VerifyPassword(int loginEmpNum);
    int loginEmployeeNum;
    int databaseEmployeeNum;
    int empNumRetry;
    string loginPassword;
    string databasePassword;

public:
    int VerifyEmployee();
};

#endif
