/**
 * @file HumanResources.cpp
 * @author your name (you@domain.com)
 * @brief
 */

#include "HumanResources.h"

HumanResources::HumanResources()
{
    // Constructor
}

void HumanResources::changeManager()
{
    string emp_data = "Data/employee_details.csv";

    cout << "\n----- Change Manager -----" << endl;
    cout << "\nEnter the employee number you would like to change" << endl;
    cin >> empNum;

    cout << "\nEnter employee's new manager's employee number" << endl;
    cin >> newManager;

    Employee emp;
    emp.editData(emp_data, "Data/temp.csv", empNum, 6, newManager);

    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}

void HumanResources ::changeJobRole()
{

    string emp_data = "Data/employee_details.csv";

    cout << "\n----- Change Job Role -----" << endl;
    cout << "\nEnter the employee number you would like to change" << endl;
    cin >> empNum;

    cout << "\nEnter employee's new job role (Enigneer, Manager, ITS, HR): " << endl;
    cin >> newRole;

    Employee emp;

    emp.editData(emp_data, "Data/temp.csv", empNum, 5, newRole);

    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}