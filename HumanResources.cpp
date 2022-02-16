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
    string line, word;
    string emp_data = "Data/employee_details.csv";
    vector<string> row;
    bool empFound = false;

    cout << "\n----- Change Manager -----" << endl;
    cout << "\nEnter the employee number you would like to change" << endl;
    cin >> empNum;

    cout << "\nEnter employee's new manager's employee number" << endl;
    cin >> newManager;

    // Open the original file as read only
    fstream fin;
    fin.open(emp_data, ios::in);

    // Open a temporary file
    fstream temp;
    temp.open("Data/temp.csv", ios::app | ios::out);

    while (!fin.eof())
    {
        while (getline(fin, line))
        {
            // Clear row vector to append data
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
                tempEmpNum = stoi(row[0]);
            }

            if (tempEmpNum != empNum)
            {
                for (int i = 0; i < row.size(); i++)
                {
                    temp << row[i] << ",";
                }
                temp << "\n";
            }
            else
            {
                empFound = true;
                for (int i = 0; i < row.size() - 1; i++)
                {
                    temp << row[i] << ",";
                }
                temp << newManager << ",";
                temp << "\n";
            }
        }
    }

    if (empFound == false)
    {
        cout << "Unable to find employee with employee number " << empNum << endl;
    }
    else
    {
        cout << "\nNew manager has been successfully changed!\n"
             << endl;
    }
    fin.close();
    temp.close();
    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}