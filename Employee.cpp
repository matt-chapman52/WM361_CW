/**
 * @file Employee.cpp
 * @author your name (you@domain.com)
 * @brief
 */
#include "Employee.h"

Employee::Employee()
{
}

int Employee::showOptions()
{
    int option;

    cout << "\n----- Welcome -----"
            "\nWhat would you like to do?"
         << endl;
    cout << "(1) Show my personal details" << endl;
    cout << "(2) Change my personal details" << endl;
    cout << "(3) Leave Menu" << endl;
    cout << "(4) Show more options" << endl;
    cout << "(5) Exit" << endl;
    cin >> option;

    return option;
}

int Employee::isManager(int empNum)
{
    string emp_details = "Data/employee_details.csv";
    string line, word;
    vector<string> row;
    int tempEmpNum;

    fstream file;
    file.open(emp_details, ios::in);

    while (!file.eof())
    {
        while (getline(file, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }
            tempEmpNum = stoi(row[6]);

            if (empNum == tempEmpNum)
            {
                file.close();
                return 1;
            }
        }
    }
    file.close();
    return 0;
}

void Employee::getPersonalDetails()
{
    string emp_details = "Data/employee_details.csv";
    vector<string> row;
    int tempEmpNum;

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
    string emp_details = "Data/employee_details.csv";
    vector<string> row;
    int decision;
    string newData;

    cout << "\n-----Change Personal Details-----" << endl;

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
        editData(emp_details, "Data/temp.csv", employeeNumber, 0, 1, newData, 1);
        break;
    case 2:
        cout << "Enter new surname name: " << endl;
        cin >> newData;
        editData(emp_details, "Data/temp.csv", employeeNumber, 0, 2, newData, 1);
        break;
    }
    remove("Data/employee_details.csv");
    rename("Data/temp.csv", "Data/employee_details.csv");
}

void Employee::requestLeave()
{
    int oneMore = 1;
    while (oneMore == 1)
    {

        vector<string> row;
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

        while (inputCheck == 1)
        {
            int another;

            cout << "\nWould you look to book another absence?" << endl;
            cout << "(1) Yes" << endl;
            cout << "(2) No" << endl;

            cin >> another;

            if (another == 1)
            {
                inputCheck = 0;
            }
            else if (another == 2)
            {
                oneMore = 0;
                break;
            }
        }
    }
}

void Employee::viewLeave()
{
    int addNum;
    int showLeave = 1;
    while (showLeave == 1) {
        addNum = listLeave(employeeNumber);

        int exitNum = addNum + 1;

        int inputCheck = 1;
        while (inputCheck == 1) {
            cout << "Enter a REQUEST NUMBER to EDIT or DELETE request,";
            cout << "\n(" << addNum << ") to REQUEST NEW LEAVE or,";
            cout << "\n(" << exitNum << ") to EXIT to MAIN MENU" << endl;
            string input;
            cin >> input;
            try {
                int option = stoi(input);
                inputCheck = 0;

                if (option < addNum && option > 0) {
                    changeLeave(option);
                } else if (option == addNum) {
                    requestLeave();
                } else if (option == exitNum) {
                    showLeave = 0;
                }
            }
            catch (...) {
                cout << "\nInvalid Entry";
            }

        }
    }

}

void Employee::changeLeave(int index)
{
    string newData;
    string question[] = {"start","end"};

    cout << "Would you like to:" << endl;
    cout << "(1) Edit request" << endl;
    cout << "(2) Delete request" << endl;
    int deleteOrEdit;
    cin >> deleteOrEdit;


    switch (deleteOrEdit) {

        case 1:
            for (int i = 2; i < 5; i++) {
                if (i == 4) {
                    newData = "In Review";
                } else {
                    cout << "\nEnter new " << question[(i - 2)] << " date in form DDMMYYYY: " << endl;
                    cin >> newData;
                }

                editData("Data/employee_leave.csv", "Data/temp.csv", employeeNumber, 0, i, newData, index);
                remove("Data/employee_leave.csv");
                rename("Data/temp.csv", "Data/employee_leave.csv");
            }
        break;
        case 2:
            deleteData("Data/employee_leave.csv", "Data/temp.csv", employeeNumber,index);
            remove("Data/employee_leave.csv");
            rename("Data/temp.csv", "Data/employee_leave.csv");
            break;
    }
}

int Employee::listLeave(int empNum)
{
    vector<string> data;
    vector<vector<string> > all_emp_leave;
    all_emp_leave = readMultipleData("Data/employee_leave.csv", 0, employeeNumber);
    // data = readData("Data/employee_leave.csv", employeeNumber);

    cout << "Your leave: " << endl;

    for (int i = 0; i < all_emp_leave.size(); i++)
    {
        cout << "(" << i + 1 << ") ";
        cout << " | Start: " << all_emp_leave[i][2];
        cout << " | End: " << all_emp_leave[i][3];
        cout << " | Status: " << all_emp_leave[i][4] << endl;
    }

    int addNum = all_emp_leave.size() + 1;
    return addNum;

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

            if (empNum == tempEmpNum)
            {
                output = row;
                empFound = true;
            }
        }
        if (empFound == false)
        {
            output.push_back("Error in retrieving data");
            cout << "Employee not found - unable to retrieve data" << endl;
        }
    }
    file.close();
    return output;
}

vector<vector<string> > Employee::readMultipleData(string fileName, int rowPos, int num)
{
    string line, word;
    vector<string> row;
    vector<vector<string> > output;
    int tempNum;
    //    bool empFound = false;

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
            }
            tempNum = stoi(row[rowPos]);
            if (num == tempNum)
            {
                output.push_back(row);
            }
        }
    }
    file.close();
    return output;
}

vector<string> Employee::editData(string fileName, string tempName, int empNum, int empCol,  int field, string newData, int index)
{
    string line, word;
    vector<string> row, output;
    int tempEmpNum;
    bool empFound = false;
    int count = 1;

    // Open the current file as read-only
    fstream file;
    file.open(fileName, ios::in);

    // Open a temporary file to write the data to
    fstream temp;
    temp.open(tempName, ios::app | ios::out);

    // Perform until end of file is reached
    while (!file.eof())
    {
        while (getline(file, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ',')){
                // Append to an empty vector
                row.push_back(word);
            }

            tempEmpNum = stoi(row[empCol]);
            if (tempEmpNum != empNum)
            {
                // Re-write the data
                for (int i = 0; i < row.size(); i++)
                {
                    temp << row[i] << ",";
                }
                temp << "\n";

            }
            else if ((tempEmpNum == empNum) && (count == index))
            {
                empFound = true;
                output = row;
                for (int i = 0; i < row.size(); i++) {
                    if (i == field) {
                        // Replace the current data with new data
                        temp << newData << ",";
                    } else {
                        temp << row[i] << ",";
                    }
                }
                temp << "\n";
                count += 1;
            }
            else
            {
                for (int i = 0; i < row.size(); i++)
                {
                    temp << row[i] << ",";
                }
                temp << "\n";
                count += 1;
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

void Employee::deleteData(string fileName, string tempFile, int empNum, int index)
{
    string line, word;
    vector<string> row;
    int tempEmpNum;
    int count = 1;

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
                if (tempEmpNum == empNum && count != index)
                {
                    temp << row[i] << ",";
                }
            }
            temp << "\n";
            if (tempEmpNum == empNum)
            {
                count++;
            }
        }
    }
    file.close();
    temp.close();
}