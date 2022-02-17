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
    string emp_details = "Data/employee_details.csv";
    vector<string> row;
    int tempEmpNum;

    cout << "Enter employee number: " << endl;
    cin >> employeeNumber;

    // Method for reading data from csv file
    row = readData(emp_details, employeeNumber);

    cout << "\n----- Personal Details ------\n"
         << endl;
    cout << "Employee Number: " << row[0] << endl;
    cout << "First Name: " << row[1] << endl;
    cout << "Surname: " << row[2] << endl;
    cout << "Email: " << row[3] << endl;
}

void Employee::changePersonalDetails()
{
    // string line, word;
    string emp_details = "Data/employee_details.csv";
    vector<string> row;
    int decision;
    string newData;
    // int tempEmpNumber;
    // string newFirstName, newSurname, newGender, newAge;
    cout << "\n-----Change Personal Details-----" << endl;

    cout << "Enter employee number: " << endl;
    cin >> employeeNumber;

    readData(emp_details, employeeNumber);

    cout << "\n What would you like to change?"
         << "\n(1) First Name"
         << "\n(2) Surname" << endl;
    cin >> decision;

    switch (decision)
    {
    case 1:
        cout << "Enter new first name: " << endl;
        cin >> newData;
        editData(emp_details, "Data/temp.csv", employeeNumber, 1, newData);
        break;
    case 2:
        cout << "Enter new surname name: " << endl;
        cin >> newData;
        editData(emp_details, "Data/temp.csv", employeeNumber, 2, newData);
        break;
    }

    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}

void Employee::requestLeave()
{
    // TO DO:-
    // Command line interface to change leave. Details stored in a .txt file
}

void Employee::viewLeave()
{
    string line, word, startDate, endDate;
    string leave_details = "Data/employee_leave.csv";
    vector<string> row;
    int tempEmpNum;
    int option;

    cout << "Enter employee number: " << endl;
    cin >> employeeNumber;

    // Open file as read only
    fstream fin;
    fin.open(leave_details, ios::in);

    while (!fin.eof())
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
            // push all start and end dates into a vector then print once file is finished
        }
    }

    // Print leave

    // Ask user what to do next

    cout << "\n----- Change and Request Leave -----"
         << "\nWhat would you like to do?"
         << endl;
    cout << "(1) Request Leave" << endl;
    cout << "(2) Change Leave" << endl;
    cout << "(3) Exit" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "\n----- Request Leave ------" << endl;
        cout << "\nEnter start date" << endl;
        cin >> startDate;
        cout << "Enter end date" << endl;
        cin >> endDate;

    case 2:

    case 3:

    default:
        cout << "Enter a value between 1 and 3";
        break;
    }

    // Return to home page
}

void Employee::changeLeave()
{
}

vector<string> Employee::readData(string fileName, int empNum)
{
    string line, word;
    vector<string> row, output;
    int tempEmpNum;

    fstream file;
    file.open(fileName, ios::in);

    while (!file.eof())
    {
        while (getline(file, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
                tempEmpNum = stoi(row[0]);
            }

            if (empNum == tempEmpNum)
            {
                output = row;
            }
            else
            {
                output.push_back("Error in retrieving data");
                cout << "Unable to retrieve data" << endl;
            }
        }
    }

    file.close();
    return output;
}

vector<string> Employee::editData(string fileName, string tempName, int empNum, int field, string newData)
{
    string line, word;
    vector<string> row, output;
    int tempEmpNum;
    bool empFound = false;

    fstream file;
    file.open(fileName, ios::in);

    fstream temp;
    temp.open(tempName, ios::app | ios::out);

    while (!file.eof())
    {
        while (getline(file, line))
        {
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
                output = row;
                for (int i = 0; i < row.size(); i++)
                {
                    if (i == field)
                    {
                        temp << newData << ",";
                    }
                    else
                    {
                        temp << row[i] << ",";
                    }
                }
                temp << "\n";
            }
        }
    }
    if (empFound == false)
    {
        output.push_back("Error in retrieving data");
        cout << "Unable to retrieve data" << endl;
    }

    file.close();
    temp.close();

    return output;
}

void Employee::writeData(string fileName, vector<string> data)
{
    fstream file;
    cout << fileName << endl;
    file.open(fileName, ios::app | ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < data.size(); i++)
        {
            file << data[i] << ",";
        }
        file << "\n";
        cout << "Data successfully appended!" << endl;
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}
