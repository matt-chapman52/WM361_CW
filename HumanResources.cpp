/**
 * @file HumanResources.cpp
 * @author 1943001
 * @brief
 */

#include "HumanResources.h"

HumanResources::HumanResources()
{
    int option;

    cout << "\n----- HR Menu ----"
         << "\nWhat would you like to do?" << endl
         << "(1) Change an employee's manager" << endl
         << "(2) Change an employee's job role" << endl
         << "(3) Return" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        changeManager();
        break;
    case 2:
        changeJobRole();
        break;
    case 3:
        break;
    default:
        cout << "Enter a value between 1 and 3" << endl;
    }
}

void HumanResources::changeManager()
{
    string emp_data = "Data/employee_details.csv";

    cout << "\n----- Change Manager -----" << endl
         << "\nEnter the employee number you would like to change" << endl;
    cin >> empNum;

    cout << "\nEnter employee's new manager's employee number" << endl;
    cin >> newManager;

    editData(emp_data, "Data/temp.csv", empNum, 0, 6, newManager, 1);

    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}

void HumanResources ::changeJobRole()
{

    string emp_data = "Data/employee_details.csv";

    cout << "----- Change Job Role -----" << endl
         << "Enter the employee number you would like to change" << endl;
    cin >> empNum;

    cout << "Enter employee's new job role (Enigneer, Manager, ITS, HR): " << endl;
    cin >> newRole;

    editData(emp_data, "Data/temp.csv", empNum, 0, 5, newRole, 1);

    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}