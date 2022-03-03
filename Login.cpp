/**
 * @file Login.cpp
 * @author Jack Pang (u1942995@live.warwick.ac.uk)
 * @brief
 */

#include "Login.h"

int Login::verifyEmployee()
{
    cout << "\n----- Welcome -----"
         << "\nLogin to Continue"
         << "\nPlease enter your employee number" << endl;
    cin >> loginEmployeeNum;

    string emp_details = "Data/employee_details.csv";

    empNumRetry = 0;
    attemptsLeft = 5;

    bool empNumValid = verifyEmpNum(loginEmployeeNum, emp_details);

    if (empNumValid == true)
    {
        bool passwordValid = verifyPassword(loginEmployeeNum);
        
        if (passwordValid == true)
        {
            cout << "\nLogin successful!" << endl;
            return loginEmployeeNum;
        }
        else
        {
            cout << "\nLogin unsuccessful" << endl;
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

bool Login::verifyEmpNum(int loginEmpNum, string dataFile)
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
        return validReEmpNum = reVerifyEmpNum(dataFile);
    }
}

bool Login::verifyPassword(int loginEmpNum)
{
    cout << "\nPlease enter your password. If you have forgotten your password, reset it by entering 1" << endl;
    cin >> loginPassword;
    databasePassword = userData[4];
    if (loginPassword == "1")
    {
        bool resetStatus = resetPassword();
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
        if (attemptsLeft !=0)
        {
            cout << "\nIncorrect password, try again (you have " << attemptsLeft << " attempts left)"<< endl;
            attemptsLeft--;
            return verifyPassword(loginEmpNum);
        }
        else
        {
            cout << "\nYou have entered an incorrect password too many times. Please restart the program" << endl;
            return false;
        }
        
    }  
}

bool Login::reVerifyEmpNum(string dataFile)
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
            return validateReEmpNum = verifyEmpNum(reloginEmpNum, dataFile);
        }
    } 
}

bool Login::resetPassword()
{
    string usrEmail = userData[3];
    srand( time(NULL) );
    int uCode = rand() %1000+9000;
    int enteredUCode;
    string newPassword;
    string emp_details = "Data/employee_details.csv";

    cout << "\nWe have sent a unique 4 digit code to " << usrEmail << endl;
    cout << "\nEnter it below to reset your password" << endl;
    cout <<"\nFor demonstration purposes enter the random 4 digit code: " << uCode << endl;
    cin >> enteredUCode;

    if (enteredUCode == uCode)
    {
        cout << "\nEnter your new password:" << endl;
        cin >> newPassword;
        if (newPassword != "1")
        {
            editData(emp_details, "Data/temp.csv", loginEmployeeNum, 0, 4, newPassword, 1);
            remove("Data/employee_details.csv");
            rename("Data/temp.csv", "Data/employee_details.csv");
            cout << "\nYour password has been reset" << endl;
            return true;
        }
        else
        {
            cout << "\nChoose a new password other than 1" << endl;
            return false;
        }
    }
    else 
    {
        cout << "\nCode does not match, password reset failed" << endl;
        return false;
    }
}


