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
    vector<string> row;

    fstream fin;
    fin.open(emp_details, ios::in);

    // Get the number of rows to assign new employee numbers
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
    userManager = 0;

    // Assign data to row vector
    row.push_back(to_string(userEmployeeNumber));
    row.push_back(userFirstName);
    row.push_back(userSurname);
    row.push_back(userEmail);
    row.push_back(basic_pass);
    row.push_back(userRole);
    row.push_back(to_string(userManager));

    Employee emp;
    emp.writeData(emp_details, row);
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
