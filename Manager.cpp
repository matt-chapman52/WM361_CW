//
// Created by Scott Tomlins on 26/02/2022.
//

#include "Manager.h"
// Constructor


Manager::Manager() {
    int option;

    cout << "\n----- Manager Menu ----"
         << "\nWhat would you like to do?" << endl;
    cout << "(1) Review your employees leave" << endl;
    cout << "(2) View your employees upcoming leave" << endl;
    cout << "(3) Exit" << endl;
    cin >> option;

    switch (option) {
        case 1:
            reviewLeave();
            break;
        case 2:
            viewUpcomingLeave();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Enter a value between 1 and 3" << endl;
    }
}

void Manager::reviewLeave() {
    string emp_details = "Data/employee_details.csv";
    string emp_leave = "Data/employee_leave.csv";

    Employee emp;

    vector<vector<string> > all_leave;

    all_leave = emp.readMultipleData("Data/employee_details.csv", 2, 0);

    cout << "----- Leave requested by your employees -----" << endl;

    for (int i = 0; i < all_leave.size(); i++){
        cout << "Employee: " << all_leave[i][0];
        cout << " Start: " << all_leave[i][2];
        cout << " End: " << all_leave[i][3] << endl;
    }

    cout << "----- end -----" << endl;


//    remove("Data/employee_details.csv");
//    rename("Data/temp.csv", "Data/employee_details.csv");
}

void Manager::viewUpcomingLeave(){

}