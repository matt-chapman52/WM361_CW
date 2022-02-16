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

int Employee::showOptions()
{
    int option;

    cout << "\n----- Welcome -----"
            "\nWhat would you like to do?"
         << endl;
    cout << "(1) Show my personal details" << endl;
    cout << "(2) Change my personal details" << endl;
    cout << "(3) Request Leave" << endl;
    cout << "(4) View Leave" << endl;
    cout << "(5) Change Leave" << endl;
    cout << "(6) Show more options" << endl;
    cout << "(7) Exit" << endl;
    cin >> option;

    return option;
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
    string line, word;
    string emp_details = "Data/employee_details.csv";
    vector<string> row;
    int tempEmpNumber;
    string newFirstName, newSurname, newGender, newAge;

    cout << "Enter employee number: " << endl;
    cin >> employeeNumber;

    // Open file as read-only
    fstream fin;
    fin.open(emp_details, ios::in);

    // Open a temporary file for read and write
    fstream temp;
    temp.open("Data/temp.csv", ios::app | ios::out);

    cout << "\n----- Change Personal Details -----\n"
         << endl;
    cout << "Enter new First Name: " << endl;
    cin >> newFirstName;
    cout << "Enter new Surname: " << endl;
    cin >> newSurname;
    cout << "Enter new Gender: " << endl;
    cin >> newGender;
    cout << "Enter new Age: " << endl;
    cin >> newAge;

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
                tempEmpNumber = stoi(row[0]);
                password = row[4];
            }

            if (tempEmpNumber != employeeNumber)
            {
                for (int i = 0; i < row.size(); i++)
                {
                    temp << row[i] << ',';
                }
                temp << '\n';
            }
            else
            {
                temp << employeeNumber << ","
                     << newFirstName << ","
                     << newSurname << ","
                     << email << ","
                     << password << ","
                     << "\n";
            }
        }
    }
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