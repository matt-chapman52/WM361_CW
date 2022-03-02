//
// Created by Scott Tomlins on 26/02/2022.
//

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Employee.h"

using namespace std;

class Manager : public Employee
{
public:
    Manager(int num);
    void reviewLeave(vector<vector<string> > all_leave);
    void viewUpcomingLeave(vector<vector<string> > all_leave);

//private:

};

#endif
