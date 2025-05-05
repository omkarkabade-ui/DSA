//experiment 12
#include <bits/stdc++.h>
#define max 20
using namespace std;

// Structure of Employee
struct employee {
    string name;
    long int code;
    string designation;
    int exp;
    int age;
};

int num = 0; // Initialize num to 0
employee emp[max]; // Employee array

void showMenu();

// Function to build the given datatype
void build() {
    cout << "Build The Table\n";
    cout << "Maximum Entries can be " << max << "\n";
    cout << "Enter the number of Entries required: ";
    cin >> num;

    if (num > max) {
        cout << "Maximum number of Entries are 20\n";
        num = max;
    }

    cout << "Enter the following data:\n";
    cin.ignore(); // Ignore newline before taking string input

    for (int i = 0; i < num; i++) {
        cout << "Name: ";
        getline(cin, emp[i].name);

        cout << "Employee ID: ";
        cin >> emp[i].code;
        cin.ignore(); // Ignore newline

        cout << "Designation: ";
        getline(cin, emp[i].designation);

        cout << "Experience: ";
        cin >> emp[i].exp;

        cout << "Age: ";
        cin >> emp[i].age;
        cin.ignore(); // Ignore newline before next input
    }
}

// Function to insert a new employee
void insert() {
    if (num < max) {
        int i = num++;
        cout << "Enter the information of the Employee\n";
        cin.ignore(); // Ignore newline

        cout << "Name: ";
        getline(cin, emp[i].name);

        cout << "Employee ID: ";
        cin >> emp[i].code;
        cin.ignore();

        cout << "Designation: ";
        getline(cin, emp[i].designation);

        cout << "Experience: ";
        cin >> emp[i].exp;

        cout << "Age: ";
        cin >> emp[i].age;
    } else {
        cout << "Employee Table Full\n";
    }
}

// Function to delete an employee record
void deleteRecord() {
    cout << "Enter the Employee ID to Delete Record: ";
    int code;
    cin >> code;

    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            for (int j = i; j < num - 1; j++) {
                emp[j] = emp[j + 1];
            }
            num--;
            cout << "Record Deleted Successfully!\n";
            return;
        }
    }
    cout << "Record Not Found!\n";
}

// Function to search for an employee record
void searchRecord() {
    cout << "Enter the Employee ID to Search Record: ";
    int code;
    cin >> code;

    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            cout << "Name: " << emp[i].name << "\n";
            cout << "Employee ID: " << emp[i].code << "\n";
            cout << "Designation: " << emp[i].designation << "\n";
            cout << "Experience: " << emp[i].exp << "\n";
            cout << "Age: " << emp[i].age << "\n";
            return;
        }
    }
    cout << "Record Not Found!\n";
}

// Function to show menu
void showMenu() {
    while (true) {
        cout << "-------------------------\n";
        cout << "Employee Management System\n";
        cout << "-------------------------\n";
        cout << "Available Options:\n";
        cout << "1. Build Table\n";
        cout << "2. Insert New Entry\n";
        cout << "3. Delete Entry\n";
        cout << "4. Search a Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int option;
        cin >> option;

        switch (option) {
            case 1: build(); break;
            case 2: insert(); break;
            case 3: deleteRecord(); break;
            case 4: searchRecord(); break;
            case 5: return;
            default: cout << "Invalid option! Choose between 1-5.\n";
        }
    }
}

// Driver Code
int main() {
    showMenu();
    return 0;
}
