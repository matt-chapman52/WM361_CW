//
// Created by Scott Tomlins on 26/02/2022.
//

#include "Manager.h"
// Constructor

Manager::Manager()
{
    int option;
    string emp_details = "Data/employee_details.csv";
    string emp_leave = "Data/employee_leave.csv";
    vector<vector<string> > all_leave;

    all_leave = readMultipleData(emp_leave, 1, 0);

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

void Manager::reviewLeave(vector<vector<string> > all_leave)
{
    cout << "----- Leave requested by your employees -----" << endl;

    for (int i = 0; i < all_leave.size(); i++)
    {
        if (all_leave[i][4] == "In Review")
        {
            cout << "Employee: " << all_leave[i][0];
            cout << " | Start: " << all_leave[i][2];
            cout << " | End: " << all_leave[i][3] << endl;
        }
    }

    cout << "----- end -----" << endl;
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