/**
 * @file ITS.cpp
 * @author your name (you@domain.com)
 * @brief
 */

#include <iostream>
#include <fstream>
#include "ITS.h"

using namespace std;

// Constructor
ITS::ITS() // Name to be inputed
{
    int option;

    cout << "\n Welcome (name). What would you like to do?" << endl;
    cout << "(1) Add a new user" << endl;
    cout << "(2) Delete a user" << endl;
    cin >> option;
    if (option == 1)
    {
        addUser();
    }
    else if (option == 2)
    {
        removeUser();
    }
    else
    {
        cout << "Enter a value between 1 and 2." << endl;
        ITS();
    }
}

void ITS::addUser()
{
    // TO DO:-
    // Assign user number, basic password and email
    // Automatically assign employee number and email
    string basic_pass;
    string first_name;
    string surname;
    string email;
    int employee_number;
    int rows = 0;
    string line;
    string emp_details = "Data/employee_details.csv";

    fstream fin;

    fin.open(emp_details, ios::in);

    if (fin.is_open())
    {
        while (getline(fin, line))
            rows++;
    }

    cout << "\n Enter employee first name: ";
    cin >> first_name;
    cout << "\n Enter employee last name: ";
    cin >> surname;

    basic_pass = "password";
    employee_number = rows + 1;
    email = first_name + "." + surname + "@company.com";

    // ofstream out;
    fstream fout;
    fout.open(emp_details, ios::app | ios::out); // Append and read and write access

    cout << "\n New User: " << first_name << " " << surname << endl;

    if (fout.is_open())
    {
        fout << employee_number << ", "
             << first_name << ", "
             << surname << ", "
             << email << ", "
             << basic_pass
             << "\n";

        // out << employee_number << setw(20) << first_name << setw(20) << surname << setw(20) << email << setw(20) << basic_pass << endl;
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    // To Do: What Now????
}

void ITS::removeUser()
{
    // TO DO: -
    // Delete all details relating to the employee
    int rows = 0;
    string line;
    string emp_details = "Data/employee_details.csv";

    fstream fin;

    fin.open(emp_details, ios::in);

    if (fin.is_open())
    {
        while (getline(fin, line))
            rows++;
    }

    // Enter name
    // Search through rows
    // Check if name mathches
    // Delete row

    cout << "Number of rows: " << rows << endl;
}
