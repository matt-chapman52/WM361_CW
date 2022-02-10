/**
 * @file Employee.cpp
 * @author your name (you@domain.com)
 * @brief
 */
#include "Employee.h"

void Employee::getPersonalDetails()
{
    int rows = 0;
    string line, word;
    string emp_details = "Data/employee_details.csv";
    vector<string> row;

    cout << "\n----- View Personal Detials -----" << endl;

    // This will be automated from login details
    cout << "Enter Employee Number: " << endl;
    cin >> employeeNumber;

    fstream fin;
    fin.open(emp_details, ios::in);

    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
    }

    // TO DO:-
    // Retrieve personal details from .txt file
}

void Employee::changePersonalInformation()
{
    // TO DO:-
    // Command line iterface to change personal details in .txt file
}

void Employee::requestLeave()
{
    // TO DO:-
    // Command line interface to change leave. Details stored in a .txt file
}

void Employee::viewLeave()
{
}

void Employee::changeLeave()
{
}

void Employee::changePassword()
{
}
