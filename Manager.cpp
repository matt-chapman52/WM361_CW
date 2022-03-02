/**
 * @file Manager.cpp
 * @author u1839629
 * @brief The manager class for the employee booking system
 */

#include "Manager.h"
// Constructor

Manager::Manager(int num)
{
    employeeNumber = num;
    int option;
    string emp_details = "Data/employee_details.csv";
    string emp_leave = "Data/employee_leave.csv";
    vector<vector<string> > all_leave;

    all_leave = readMultipleData(emp_leave, 1, employeeNumber);

    cout << "\n----- Manager Menu ----"
         << "\nWhat would you like to do?" << endl;
    cout << "(1) Review your employees leave" << endl;
    cout << "(2) View your employees upcoming leave" << endl;
    cout << "(3) Exit" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        reviewLeave(all_leave);
        break;
    case 2:
        viewUpcomingLeave(all_leave);
        break;
    case 3:
        //            exit(0);
        break;
    default:
        cout << "Enter a value between 1 and 3" << endl;
    }
}

void Manager::reviewLeave(vector<vector<string> > all_leave){
    vector<int> leave_review;
    int leave_approve = 0;
    cout << "----- Leave requested by your employees -----" << endl;

    for (int i = 0; i < all_leave.size(); i++){
        if (all_leave[i][4] == "In Review"){
            leave_review.push_back(i+1);
            cout << "(" << i+1 << ") ";
            cout << "Employee: " << all_leave[i][0];
            cout << " | Start: " << all_leave[i][2];
            cout << " | End: " << all_leave[i][3] << endl;
        }
    }

    cout << "Enter the number of any leave you want to APPROVE, if not enter 0" << endl;
    cin >> leave_approve;
//    leave_approve--;

    if (count(leave_review.begin(), leave_review.end(), leave_approve)) {
        editData("Data/employee_leave.csv", "Data/temp.csv", employeeNumber, 1, 4, "Approved", leave_approve);

        remove("Data/employee_leave.csv");
        rename("Data/temp.csv", "Data/employee_leave.csv");

        cout << "Leave approved!" << endl;
    }

    cout << "Enter the number of any leave you want to DENY, if not enter 0" << endl;
    cin >> leave_approve;
//    leave_approve--;

    if (count(leave_review.begin(), leave_review.end(), leave_approve)) {
        editData("Data/employee_leave.csv", "Data/temp.csv", employeeNumber, 1, 4, "Denied", leave_approve);

        remove("Data/employee_leave.csv");
        rename("Data/temp.csv", "Data/employee_leave.csv");

        cout << "Leave denied!" << endl;
    }
}

void Manager::viewUpcomingLeave(vector<vector<string> > all_leave)
{
    cout << "----- Upcoming leave for your employees -----" << endl;

    for (int i = 0; i < all_leave.size(); i++)
    {
        if (all_leave[i][4] == "Approved")
        {
            cout << "Employee: " << all_leave[i][0];
            cout << " | Start: " << all_leave[i][2];
            cout << " | End: " << all_leave[i][3] << endl;
        }
    }

    cout << "----- end -----" << endl;
}