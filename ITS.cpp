/**
 * @file ITS.cpp
 * @author your name (you@domain.com)
 * @brief
 */

#include "ITS.h"

// using namespace std;

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

    string basic_pass;
    string first_name;
    string surname;
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
    cin >> first_name;
    cout << "\n Enter employee last name: ";
    cin >> surname;

    basic_pass = "password";
    employee_number = rows + 1;
    email = first_name + "." + surname + "@company.com";

    fstream fout;
    fout.open(emp_details, ios::app | ios::out); // Append and read and write access

    cout << "\n New User: " << first_name << " " << surname << endl;

    if (fout.is_open())
    {
        fout << employee_number << ","
             << first_name << ","
             << surname << ","
             << email << ","
             << basic_pass
             << "\n";
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
    string line, word, tempSt;
    string emp_details = "Data/employee_details.csv";
    string tempFirstName;
    string tempSurname;
    vector<string> row;

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
                employee_number = stoi(row[0]);
            }
            for (int i = 0; i < row.size(); i++)
            {
                if (stoi(row[0]) != employee_number)
                {
                    temp << row[i] << ",";
                }
            }
            temp << "\n";
        }
    }
    fin.close();
    temp.close();
    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}
