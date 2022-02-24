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

using namespace std;

class Login // Add child of employees
{
private:
    bool VerifyPassword();
    int loginEmployeeNum;
    int databaseEmployeeNum;
    string loginPassword;
    string databasePassword;

public:
    int VerifyEmployee();
};

#endif
