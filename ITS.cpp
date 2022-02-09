/**
 * @file ITS.cpp
 * @author your name (you@domain.com)
 * @brief
 */

#include <iostream>
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
    else if (option == 2) // Convert string to int ????? or cos its type int it may work?
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

    cout << "\n Enter employee first name: ";
    cin >> first_name;
    cout << "\n Enter employee last name: ";
    cin >> surname;

    ofstream out;
    string emp_details = "Data/employee_details.txt";
    out.open(emp_details, ios::app | ios::in | ios::out);

    cout << "\n New User" << endl;

    if (out.is_open())
    {
    }
    else
    {
        cout << 'Unable to open file' << endl;
    }
}

void ITS::removeUser()
{
    // TO DO: -
    // Delete all details relating to the employee
    ifstream in;
}