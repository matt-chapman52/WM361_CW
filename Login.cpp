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

    empNumRetry = 0;

    bool empNumValid = VerifyEmpNum(loginEmployeeNum, emp_details);

    if (empNumValid == true)
    {
        bool passwordValid = VerifyPassword(loginEmployeeNum);
        
        if (passwordValid == true)
        {
            cout << "/nLogin successful!" << endl;
            return loginEmployeeNum;
        }
        else
        {
            cout << "/nLogin unsuccessful" << endl;
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
        userData = row;
        return true;
    }
    else 
    {
        return validReEmpNum = ReVerifyEmpNum(dataFile);
    }
}

bool Login::VerifyPassword(int loginEmpNum)
{
    cout << "\nPlease enter your password. If you have forgotten your password, reset it by entering 1" << endl;
    cin >> loginPassword;
    databasePassword = userData[4];
    if (loginPassword == "1")
    {
        bool resetStatus = ResetPassword();
        if (resetStatus == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (loginPassword == databasePassword)
    {
        return true;
    }
    else 
    {
        cout << "/nIncorrect Password" << endl;
        return false;  
    }  
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

bool Login::ResetPassword()
{
    string usrEmail = userData[3];
    int uCode = rand() % 9000 + 1000;
    int enteredUCode;
    cout << "\nWe have sent a unique 4 digit code to " << usrEmail << endl;
    cout << "\nEnter it below to reset your password" << endl;
    cout <<"\nFor demonstration purposes enter the random 4 digit code: " << uCode << endl;
    cin >> enteredUCode;

    if (enteredUCode == uCode)
    {
        return true;
    }
    else 
    {
        return false;
    }
}


