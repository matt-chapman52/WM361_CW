/**
 * @file Login.cpp
 * @author 1942995
 * @brief Login class, verifies employee number and password. Allows for the user to change password.
 */

#include "Login.h"

// Method returns employee number if employee details are correct and 0 if they are incorrect.  
int Login::verifyEmployee()
{
    cout << "\n----- Welcome -----" << endl
         << "Login to Continue" << endl
         << "Please enter your employee number" << endl;
    cin >> loginEmployeeNum; // Obtain users entry for employee number

    string emp_details = "Data/employee_details.csv"; //Name of database file

    empNumRetry = 0; // Number of attempts of employee number entry
    attemptsLeft = 5; // Number of password attempts left

    bool empNumValid = verifyEmpNum(loginEmployeeNum, emp_details); // Check if employee number is valid

    if (empNumValid == true)
    {
        bool passwordValid = verifyPassword(loginEmployeeNum); // Verify users password
        
        if (passwordValid == true)
        {
            cout << "\nLogin successful!" << endl;
            cout << "\nWelcome " << userData[1] << endl;
            return loginEmployeeNum; // Return employee number if both employee number and password are valid
        }
        else
        {
            cout << "\nLogin unsuccessful" << endl;
            return 0; // Return 0 if password is invalid
        }
    }
    else
    {
        return 0; // Return 0 if employee number is invalid
    }
}

// Method returns true/false if the employee number is valid/invalid
bool Login::verifyEmpNum(int loginEmpNum, string dataFile)
{
    int totalRows = 0;
    ifstream file(dataFile);
    string line;
    vector<string> row;
    int employeeNumber;
    bool validReEmpNum;
    bool withinRange;

    while (getline(file, line))
    {
        totalRows++; // Obtain number of database rows
    }

    if (loginEmpNum <= totalRows) // Only read data if the entered employee number is <= number of database rows
    {
        withinRange = true;
        row = readData(dataFile, loginEmpNum);
        employeeNumber = stoi(row[0]); // Obtain database employee number
    }
    else
    {
        withinRange = false;
    }
        
    if (withinRange == true & loginEmpNum == employeeNumber) // Check the entered employee number has not been deleted
    {
        userData = row;
        return true;
    }
    else 
    {
        return validReEmpNum = reVerifyEmpNum(dataFile); // If invalid, re-verify
    }
}

// Method returns true/false if password is valid/invalid
bool Login::verifyPassword(int loginEmpNum)
{
    cout << "\nPlease enter your password. If you have forgotten your password, reset it by entering 1" << endl;
    cin >> loginPassword;
    databasePassword = userData[4];

    if (loginPassword == "1")
    {
        bool resetStatus = resetPassword(); // Call reset password method

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

// Method returns true/false if re-entered employee number is valid/invalid
bool Login::reVerifyEmpNum(string dataFile)
{
    int reloginEmpNum;

    cout << "\nWe couldn't find your details. Enter your employee number to try again or enter 0 to register your account" << endl;
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
            return verifyEmpNum(reloginEmpNum, dataFile);
        }
    } 
}

// Method returns true/false if password is successfully/unsuccessfully reset
bool Login::resetPassword()
{
    string usrEmail = userData[3];
    srand( time(NULL) );
    int uCode = rand() %1000+9000; // Generate random 4 digit number
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
            editData(emp_details, "Data/temp.csv", loginEmployeeNum, 0, 4, newPassword, 1); // Edit database password 
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


