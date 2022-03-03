/**
 * @file Employee.h
 * @author 1943001
 * @brief Employee header file containing declarations relating to Employee.cpp
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
    string gender;
    int age;
    string password;
    int managerEmpNum;

public:
    Employee();
    int employeeNumber;
    int showOptions();
    void getPersonalDetails();
    void changePersonalDetails();
    void requestLeave();
    void viewLeave();
    void changeLeave(int index);
    int listLeave(int empNum);
    int isManager(int empNum);
    vector<string> readData(string fileName, int empNum);
    vector<vector<string> > readMultipleData(string fileName, int rowPos, int num);
    vector<string> editData(string fileName, string tempName, int empNum, int empCol, int field, string newData, int index);
    void writeData(string fileName, vector<string> data);
    void deleteData(string fileName, string tempFile, int empNum, int index);
};

#endif
