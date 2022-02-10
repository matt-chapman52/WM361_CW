/**
 * @file ITS.h
 * @author your name (you@domain.com)
 * @brief
 */

#ifndef ITS_H
#define ITS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class ITS // Add child of employees
{
public:
    ITS();
    void addUser();
    void removeUser();

private:
    string userFirstName;
    string userSurname;
    int userEmployeeNumber;
};

#endif
