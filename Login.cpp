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
    
    return loginEmployeeNum;
    /*s
    int rows = 0;
    int choice;
    string line;
    ifstream file("Data/employee_details.csv");

    while (getline(file, line))
    {
        rows++;
    }

    if (loginEmployeeNum <= rows)
    {
        // possibly add "welcome (first and second name)"
        VerifyPassword();
    }
    else
    {
        // "This employee number does not exist, enter 1 to try again or 2 to register for the annual leave service with IT"
        if (choice==1)
        {
            Login();
        }
        else
        {
            //"Please contact IT on -------- to register an account"
        }
        
    }
    */

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

