/**
 * @file ITS.cpp
 * @author your name (you@domain.com)
 * @brief
 */

#include "ITS.h"
// Constructor
ITS::ITS()
{
    int option;

    cout << "\n----- Welcome ----"
         << "\nWhat would you like to do?" << endl;
    cout << "(1) Add a new user" << endl;
    cout << "(2) Delete a user" << endl;
    cout << "(3) Exit" << endl;
    cin >> option;
    if (option == 1)
    {
        addUser();
    }
    else if (option == 2)
    {
        removeUser();
    }
    else if (option == 3)
    {
        exit(0);
    }
    else
    {
        cout << "Enter a value between 1 and 3." << endl;
    }
}

void ITS::addUser()
{

    string basic_pass;
    string email;
    int rows = 0;
    string line;
    string emp_details = "Data/employee_details.csv";

    fstream fin;

    fin.open(emp_details, ios::in);

    // Get the number of rows to addign new employee numbers
    if (fin.is_open())
    {
        while (getline(fin, line))
            rows++;
    }

    cout << "\n Enter employee first name: ";
    cin >> userFirstName;
    cout << "\n Enter employee last name: ";
    cin >> userSurname;

    basic_pass = "password";
    userEmployeeNumber = rows + 1;
    email = userFirstName + "." + userSurname + "@company.com";

    fstream fout;
    fout.open(emp_details, ios::app | ios::out); // Append and read and write access

    cout << "\n New User: " << userFirstName << " " << userSurname << endl;

    if (fout.is_open())
    {
        fout << userEmployeeNumber << ","
             << userFirstName << ","
             << userSurname << ","
             << email << ","
             << basic_pass
             << "\n";

        cout << "\n----- New user added -----"
             << "\nEmployee Number: " << userEmployeeNumber
             << "\nName: " << userFirstName << " " << userSurname
             << "\nEmail: " << email << endl;
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    // To Do: What Now????
}

void ITS::removeUser()
{
    int rows = 0;
    string line, word, tempSt;
    string emp_details = "Data/employee_details.csv";
    string tempFirstName;
    string tempSurname;
    vector<string> row;
    userEmployeeNumber = 0;

    fstream fin;

    fin.open(emp_details, ios::in);

    fstream temp;

    temp.open("Data/temp.csv", ios::app | ios::out);

    cout << "----- Remove a user from the system -----" << endl;
    cout << "Enter employee first name: " << endl;
    cin >> userFirstName;
    cout << "Enter employee surname: " << endl;
    cin >> userSurname;

    if (fin.is_open())
    {

        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
                tempFirstName = row[1];
                tempSurname = row[2];
            }
            cout << row[1] << endl;
            if ((userFirstName.compare(tempFirstName) == 0) && (userSurname.compare(tempSurname) == 0))
            {
                userEmployeeNumber = stoi(row[0]);
            }
            for (int i = 0; i < row.size(); i++)
            {
                if (stoi(row[0]) != userEmployeeNumber)
                {
                    temp << row[i] << ",";
                }
            }
            temp << "\n";
        }
        if (userEmployeeNumber == 0)
        {
            cout << "Unable to find employee in database" << endl;
        }
    }
    fin.close();
    temp.close();
    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}
