/**
 * @file ITS.cpp
 * @author 1943001
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

    switch (option)
    {
    case 1:
        addUser();
        break;
    case 2:
        removeUser();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Enter a value between 1 and 3" << endl;
    }
}

void ITS::addUser()
{

    string basic_pass, line;
    int rows = 0;
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
    userEmail = userFirstName + "." + userSurname + "@company.com";
    userRole = "employee";
    userManager = 0000;

    fstream fout;
    fout.open(emp_details, ios::app | ios::out); // Append and read and write access

    cout << "\n New User: " << userFirstName << " " << userSurname << endl;

    if (fout.is_open())
    {
        fout << userEmployeeNumber << ","
             << userFirstName << ","
             << userSurname << ","
             << userEmail << ","
             << basic_pass << ","
             << userRole << ","
             << userManager << ","
             << "\n";

        cout << "\n----- New user added -----"
             << "\nEmployee Number: " << userEmployeeNumber
             << "\nName: " << userFirstName << " " << userSurname
             << "\nEmail: " << userEmail << endl;
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
    string line, word;
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
