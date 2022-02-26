/**
 * @file Employee.cpp
 * @author your name (you@domain.com)
 * @brief
 */
#include "Employee.h"

Employee::Employee() {
    // TO DO - USe job role to call additional classes
}

int Employee::showOptions() {
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

int Employee::isManager(int empNum) {
    string emp_details = "Data/employee_details.csv";
    string line, word;
    vector <string> row;
    int tempEmpNum;

    fstream file;
    file.open(emp_details, ios::in);

    while (!file.eof()) {
        while (getline(file, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            tempEmpNum = stoi(row[6]);

            if (empNum == tempEmpNum) {
                file.close();
                return 1;
            }
        }
    }
    file.close();
    return 0;

}

void Employee::getPersonalDetails() {
    string emp_details = "Data/employee_details.csv";
    vector <string> row;
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

void Employee::changePersonalDetails() {
    // string line, word;
    string emp_details = "Data/employee_details.csv";
    vector <string> row;
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

    switch (decision) {
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

void Employee::requestLeave() {
    // TO DO:-
    // Command line interface to change leave. Details stored in a .txt file
}

void Employee::viewLeave() {
    vector <string> row;
    string leave_details = "Data/employee_leave.csv";
    string emp_details = "Data/employee_details.csv";
    int option;
    string startDate, endDate;

    cout << "Enter employee number: " << endl;
    cin >> employeeNumber; // Automatically done once login code complete

    // Ask user what to do next

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
            // TO DO: - Henry. Can we append more dates to the same row for people who have booked in multiple leave dates.?
            // Or just have different rows but make sure we read and display them all.

        case 2:
            // TO DO: - Henry
        case 3:
            // TO DO: - Henry
        case 4:
            exit(0);

        default:
            cout
                    << "Enter a value between 1 and 4";
            break;
    }

    // Return to home page
}

void Employee::changeLeave() {
}

vector <string> Employee::readData(string fileName, int empNum) {
    string line, word;
    vector <string> row, output;
    int tempEmpNum;
    bool empFound = false;

    fstream file;
    file.open(fileName, ios::in);

    while (!file.eof()) {
        while (getline(file, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
                tempEmpNum = stoi(row[0]);
            }

            if (empNum == tempEmpNum) {
                output = row;
                empFound = true;
            }
            if (empFound == false) {
                output.push_back("Error in retrieving data");
                cout << "Unable to retrieve data" << endl;
            }
        }
    }
    file.close();
    return output;
}

vector <vector<string> > Employee::readMultipleData(string fileName, int rowPos, int num) {
    string line, word;
    vector <string> row;
    vector <vector<string> > output;
    int tempNum;
//    bool empFound = false;

    fstream file;
    file.open(fileName, ios::in);

    while (!file.eof()) {
        while (getline(file, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            tempNum = stoi(row[rowPos]);
            if (num == tempNum) {
                output.push_back(row);
            }
        }
    }
    file.close();
    return output;
}

vector <string> Employee::editData(string fileName, string tempName, int empNum, int field, string newData) {
    string line, word;
    vector <string> row, output;
    int tempEmpNum;
    bool empFound = false;

    // Open the current file as read-only
    fstream file;
    file.open(fileName, ios::in);

    // Open a temporary file to write the data to
    fstream temp;
    temp.open(tempName, ios::app | ios::out);

    // Perform until end of file is reached
    while (!file.eof()) {
        while (getline(file, line)) {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ',')) {
                // Append to an empty vector
                row.push_back(word);
                tempEmpNum = stoi(row[0]);
            }

            if (tempEmpNum != empNum) {
                // Re-write the data
                for (int i = 0; i < row.size(); i++) {
                    temp << row[i] << ",";
                }
                temp << "\n";
            } else {
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
            }
        }
    }
    if (empFound == false) {
        output.push_back("Error in retrieving data");
        cout << "Unable to retrieve data" << endl;
    }

    file.close();
    temp.close();

    return output;
}

void Employee::writeData(string fileName, vector <string> data) {
    fstream file;
    file.open(fileName, ios::app | ios::out);

    if (file.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            file << data[i] << ",";
        }
        file << "\n";
        cout << "Data successfully appended!" << endl;
    } else {
        cout << "Unable to open file" << endl;
    }
}

void Employee::deleteData(string fileName, string tempFile, int empNum) {
    string line, word;
    vector <string> row;
    int tempEmpNum;

    // Open the file with data as read-only
    fstream file;
    file.open(fileName, ios::in);

    // Open a temporary file where data can be appended
    fstream temp;
    temp.open(tempFile, ios::app | ios::out);

    while (!file.eof()) {
        while (getline(file, line)) {
            // Split each line up
            row.clear();
            stringstream s(line);

            while (getline(s, word, ',')) {
                // Add each word to a vector cell
                row.push_back(word);
                tempEmpNum = stoi(row[0]);
            }

            // Only write the data which is not to be deleted
            for (int i = 0; i < row.size(); i++) {
                if (tempEmpNum != empNum) {
                    temp << row[i] << ",";
                }
            }
            temp << "\n";
        }
    }
    file.close();
    temp.close();
}