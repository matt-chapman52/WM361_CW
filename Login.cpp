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

    bool empNumValid = VerifyEmpNum(loginEmployeeNum);

    if (empNumValid == true)
    {
        bool passwordValid = VerifyPassword(loginEmployeeNum);
        
        if (passwordValid == true)
        {
            return loginEmployeeNum
        }
    }
    else
    {
        return 0;
    }
}

bool Login::VerifyEmpNum()
{

}

bool Login::VerifyPassword()
{
    cout << "/nEnter your Password" << endl;
    cin >> loginPassword;
    cout << "/nLogin successful!" << endl;
    // return employee number if successful
    // return 0 if unsuccessful
    return false;
}

