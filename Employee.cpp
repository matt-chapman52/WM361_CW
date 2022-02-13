/**
 * @file Employee.cpp
 * @author your name (you@domain.com)
 * @brief
 */
#include "Employee.h"

Employee::Employee()
{
    // TO DO - USe job role to call additional classes
}

void Employee::getPersonalDetails()
{
    string line, word;
    string emp_details = "Data/employee_details.csv";
    vector<string> row;
    int tempEmpNum;
    employeeNumber = 0;

    cout << "Enter employee number: " << endl;
    cin >> employeeNumber;

    // Open file as read-only
    fstream fin;
    fin.open(emp_details, ios::in);

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
                tempEmpNum = stoi(row[0]);
            }

            if (employeeNumber == tempEmpNum)
            {
                employeeNumber = stoi(row[0]);
                firstName = row[1];
                surname = row[2];
                email = row[3];

                cout << "\n----- Personal Details ------\n"
                     << endl;
                cout << "Employee Number: " << employeeNumber << endl;
                cout << "First Name: " << firstName << endl;
                cout << "Surname: " << surname << endl;
                cout << "Gender: " << gender << endl;
                cout << "Age: " << age << endl;
            }
        }
        if (employeeNumber == 0)
        {
            cout << "Unable to find employee in database" << endl;
        }
    }
    fin.close();
}

void Employee::changePersonalDetails()
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