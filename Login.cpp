/**
 * @file Login.cpp
 * @author Jack Pang (u1942995@live.warwick.ac.uk)
 * @brief
 */

#include "Login.h"

int Login::VerifyEmployee()
{
    cout << "\n----- Welcome -----"
         << "\nLogin to Continue"
         << "\nPlease enter your employee number" << endl;
    cin >> loginEmployeeNum;

    string emp_details = "Data/employee_details.csv";
    vector<string> row;

    // Method for reading data from csv file
    row = readData(emp_details, loginEmployeeNum);

    empNumRetry = 0;

    bool empNumValid = VerifyEmpNum(loginEmployeeNum, emp_details);

    if (empNumValid == true)
    {
        bool passwordValid = VerifyPassword(loginEmployeeNum);
        
        if (passwordValid == true)
        {
            return loginEmployeeNum;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

bool Login::VerifyEmpNum(int loginEmpNum, string dataFile)
{
    int totalRows=0;
    ifstream file(dataFile);
    string line;
    vector<string> row;
    int employeeNumber;
    bool validReEmpNum;
    bool withinRange;

    while (getline(file, line))
    {
        totalRows++; 
    }

    if (loginEmpNum <= totalRows)
    {
        withinRange = true;
        row = readData(dataFile, loginEmpNum);
        employeeNumber = stoi(row[0]);
    }
    else
    {
        withinRange = false;
    }
        
    if (withinRange == true & loginEmpNum == employeeNumber)
    {
        return true;
    }
    else 
    {
        return validReEmpNum = ReVerifyEmpNum(dataFile);
    }
}

bool Login::VerifyPassword(int loginEmpNum)
{
    cout << "/nEnter your Password" << endl;
    cin >> loginPassword;
    cout << "/nLogin successful!" << endl;
    // return employee number if successful
    // return 0 if unsuccessful
    return true;
}

bool Login::ReVerifyEmpNum(string dataFile)
{
    int reloginEmpNum;
    bool validateReEmpNum;
    cout << "\nWe couldnt find your details. Enter your employee number to try again or enter 0 to register your account" << endl;
    cin >> reloginEmpNum;
    if (reloginEmpNum == 0)
    {
        cout << "\nContact your IT department to register for an account using itadmin@company.com" << endl;
        return false;
    }
    else
    {
        empNumRetry++;
        if (empNumRetry > 5)
        {
            cout << "\nYou have tried to reenter an employee number too many times, please run the application again" << endl;
            return false;
        }
        else
        {
            return validateReEmpNum = VerifyEmpNum(reloginEmpNum, dataFile);
        }
    } 
}


