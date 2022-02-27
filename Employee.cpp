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

    cout << "Enter employee number: " << endl;
    cin >> employeeNumber; // Automatically done once login code complete

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

    // Display the Data in the console
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
    int oneMore = 1;
    while (oneMore == 1) {

        vector <string> row;
        string leave_details = "Data/employee_leave.csv";
        string emp_details = "Data/employee_details.csv";
        string startDate, endDate;

        cout << "\n----- Request Leave ------" << endl;
        cout << "\nEnter start date in form DDMMYYYY: " << endl;
        cin >> startDate;
        cout << "Enter end date in for DDMMYYYY: " << endl;
        cin >> endDate;

        row.clear();
        row = readData(emp_details, employeeNumber);
        managerEmpNum = stoi(row[6]);

        row.clear();
        row.push_back(to_string(employeeNumber));
        row.push_back(to_string(managerEmpNum));
        row.push_back(startDate);
        row.push_back(endDate);
        row.push_back("In Review");

        writeData(leave_details, row);

        int inputCheck = 1;

        while (inputCheck == 1) {
            int another;

            cout << "\nWould you look to book another absence?" << endl;
            cout << "(1) Yes" << endl;
            cout << "(2) No" << endl;

            cin >> another;

            if (another == 1) {
                inputCheck = 0;
            }
            else if  (another == 2) {
                oneMore = 0;
                cout << oneMore << endl;
                break;
            }
        }
    }
}

void Employee::viewLeave()
{

    int option;

    cout << "\n----- Change and Request Leave -----"
         << "\nWhat would you like to do?"
         << endl;
    cout << "(1) Request Leave" << endl;
    cout << "(2) Change Leave" << endl;
    cout << "(3) View Leave" << endl;
    cout << "(4) Exit" << endl;
    cin >> option;

    switch (option) {
        case 1:
            requestLeave();
            break;

        case 2:
            //do the other ones - HENRY
            break;

        case 3:
            listLeave(employeeNumber);
            break;
        case 4:
            //Should just exit???
            break;

    }

    // Return to home page
}

void Employee::changeLeave()
{
    string startDate, endDate;
    cout << "\nEnter new start date in form DDMMYYYY: " << endl;
    cin >> startDate;
    editData("Data/employee_leave.csv", "Data/temp.csv", employeeNumber, 2, startDate);
    remove("Data/employee_leave.csv");
    rename("Data/temp.csv","Data/employee_leave.csv");
    cout << "\nEnter new end date in for DDMMYYYY: " << endl;
    cin >> endDate;
    editData("Data/employee_leave.csv", "Data/temp.csv", employeeNumber, 3, endDate);
    remove("Data/employee_leave.csv");
    rename("Data/temp.csv","Data/employee_leave.csv");

    editData("Data/employee_leave.csv", "Data/temp.csv", employeeNumber, 4, "In Review");
    remove("Data/employee_leave.csv");
    rename("Data/temp.csv","Data/employee_leave.csv");

    listLeave(employeeNumber);
}

void Employee::listLeave(int empNum)
{
    vector <string> data;
    vector <vector<string> > all_emp_leave;
    all_emp_leave = readMultipleData("Data/employee_leave.csv", 0, employeeNumber);
    //data = readData("Data/employee_leave.csv", employeeNumber);

    for (int i = 0; i < all_emp_leave.size(); i++) {
        cout << "(" << i + 1 << ") ";
        cout << " | Start: " << all_emp_leave[i][2];
        cout << " | End: " << all_emp_leave[i][3] << endl;
    }

    //cout << "(1) Start:" << data[2] << " End:" << data[3] << endl;
    int exitNum = all_emp_leave.size() + 1;

    int inputCheck = 1;
    while (inputCheck == 1){
        cout << "\nEnter leave number to edit or " << exitNum << " to exit" << endl;
        int option;
        cin >> option;

        if (option < exitNum && option > 0) {
            inputCheck = 0;
            changeLeave();

        } else if (option == exitNum) {
            inputCheck = 0;
            break;
        }
    }
}
vector<string> Employee::readData(string fileName, int empNum)
{
    string line, word;
    vector<string> row, output;
    int tempEmpNum;
    bool empFound = false;

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
            cout << tempEmpNum;

            //this is pointless <3
            if (empNum == tempEmpNum)
            {
                output = row;
                empFound = true;
                cout << tempEmpNum << endl;
            }
            cout << empFound;
            if (empFound == false)
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

    // Open the current file as read-only
    fstream file;
    file.open(fileName, ios::in);

    // Open a temporary file to write the data to
    fstream temp;
    temp.open(tempName, ios::app | ios::out);

    // Perfom until end of file is reached
    while (!file.eof())
    {
        while (getline(file, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                // Append to an empty vector
                row.push_back(word);
                tempEmpNum = stoi(row[0]);
            }

            if (tempEmpNum != empNum)
            {
                // Re-write the data
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
                        // Replace the current data with new data
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

void Employee::deleteData(string fileName, string tempFile, int empNum)
{
    string line, word;
    vector<string> row;
    int tempEmpNum;

    // Open the file with data as read-only
    fstream file;
    file.open(fileName, ios::in);

    // Open a temporary file where data can be appended
    fstream temp;
    temp.open(tempFile, ios::app | ios::out);

    while (!file.eof())
    {
        while (getline(file, line))
        {
            // Split each line up
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                // Add each word to a vector cell
                row.push_back(word);
                tempEmpNum = stoi(row[0]);
            }

            // Only write the data which is not to be deleted
            for (int i = 0; i < row.size(); i++)
            {
                if (tempEmpNum != empNum)
                {
                    temp << row[i] << ",";
                }
            }
            temp << "\n";
        }
    }
    file.close();
    temp.close();
}