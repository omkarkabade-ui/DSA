//experiment 11
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
public:
    int rollNo;
    char name[20]; // Increased name size
    char div;
    char address[50]; // Increased address size

    void accept() {
        cout << "\n\tEnter Roll Number: ";
        cin >> rollNo;
        cout << "\n\tEnter Name: ";
        cin.ignore();
        cin.getline(name, 20);
        cout << "\n\tEnter Division: ";
        cin >> div;
        cout << "\n\tEnter Address: ";
        cin.ignore();
        cin.getline(address, 50);
    }

    void acceptRollNumber() {
        cout << "\n\tEnter the new Roll No.: ";
        cin >> rollNo;
    }

    void acceptName() {
        cout << "\n\tEnter the new Name: ";
        cin.ignore();
        cin.getline(name, 20);
    }

    int getRollNo() {
        return rollNo;
    }

    void show() {
        cout << "\n\t" << rollNo << "\t\t" << name << "\t\t" << div << "\t\t" << address;
    }
};

int main() {
    int choice;
    Student s;
    fstream file, tempFile;

    do {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>> MENU <<<<<<<<<<<<<<<<<<<<";
        cout << "\n1. Insert & Overwrite\n2. Show Records\n3. Search & Edit (by Roll Number)";
        cout << "\n4. Search & Edit (by Name)\n5. Modify Roll Number\n6. Modify Name";
        cout << "\n7. Delete a Student Record\n8. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                file.open("StuRecord.txt", ios::out | ios::trunc);
                if (!file) {
                    cout << "\nError opening file!";
                    break;
                }
                do {
                    s.accept();
                    file.write((char*)&s, sizeof(s));
                    cout << "\nDo you want to enter more records? (1. Yes / 2. No): ";
                    cin >> choice;
                } while (choice == 1);
                file.close();
                break;

            case 2:
                file.open("StuRecord.txt", ios::in);
                if (!file) {
                    cout << "\nError opening file!";
                    break;
                }
                cout << "\n\tRoll No.\tName\t\tDivision\tAddress";
                while (file.read((char*)&s, sizeof(s))) {
                    s.show();
                }
                file.close();
                break;

            case 3: { // Search & Edit by Roll Number
                int roll, found = 0;
                cout << "\nEnter the Roll Number you want to modify: ";
                cin >> roll;

                file.open("StuRecord.txt", ios::in | ios::out);
                if (!file) {
                    cout << "\nError opening file!";
                    break;
                }

                while (file.read((char*)&s, sizeof(s))) {
                    if (s.getRollNo() == roll) {
                        cout << "\nRecord found. Enter new details:";
                        s.accept();

                        file.seekp(-sizeof(s), ios::cur);
                        file.write((char*)&s, sizeof(s));
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "\nRecord not found!";
                file.close();
                break;
            }

            case 4: { // Search & Edit by Name
                char searchName[20];
                int found = 0;
                cout << "\nEnter the Name you want to modify: ";
                cin.ignore();
                cin.getline(searchName, 20);

                file.open("StuRecord.txt", ios::in | ios::out);
                if (!file) {
                    cout << "\nError opening file!";
                    break;
                }

                while (file.read((char*)&s, sizeof(s))) {
                    if (strcmp(s.name, searchName) == 0) {
                        cout << "\nRecord found. Enter new details:";
                        s.accept();

                        file.seekp(-sizeof(s), ios::cur);
                        file.write((char*)&s, sizeof(s));
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "\nRecord not found!";
                file.close();
                break;
            }

            case 5: { // Modify only Roll Number
                int roll, found = 0;
                cout << "\nEnter the Roll Number you want to modify: ";
                cin >> roll;

                file.open("StuRecord.txt", ios::in | ios::out);
                if (!file) {
                    cout << "\nError opening file!";
                    break;
                }

                while (file.read((char*)&s, sizeof(s))) {
                    if (s.getRollNo() == roll) {
                        cout << "\nRecord found. Enter new Roll Number:";
                        s.acceptRollNumber();

                        file.seekp(-sizeof(s), ios::cur);
                        file.write((char*)&s, sizeof(s));
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "\nRecord not found!";
                file.close();
                break;
            }

            case 6: { // Modify only Name
                char searchName[20];
                int found = 0;
                cout << "\nEnter the Name you want to modify: ";
                cin.ignore();
                cin.getline(searchName, 20);

                file.open("StuRecord.txt", ios::in | ios::out);
                if (!file) {
                    cout << "\nError opening file!";
                    break;
                }

                while (file.read((char*)&s, sizeof(s))) {
                    if (strcmp(s.name, searchName) == 0) {
                        cout << "\nRecord found. Enter new Name:";
                        s.acceptName();

                        file.seekp(-sizeof(s), ios::cur);
                        file.write((char*)&s, sizeof(s));
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "\nRecord not found!";
                file.close();
                break;
            }

            case 7: { // Delete a record
                int roll;
                cout << "\nEnter the Roll Number of the record to delete: ";
                cin >> roll;

                file.open("StuRecord.txt", ios::in);
                tempFile.open("Temp.txt", ios::out);
                if (!file || !tempFile) {
                    cout << "\nError opening file!";
                    break;
                }

                int found = 0;
                while (file.read((char*)&s, sizeof(s))) {
                    if (s.getRollNo() != roll) {
                        tempFile.write((char*)&s, sizeof(s));
                    } else {
                        found = 1;
                    }
                }

                file.close();
                tempFile.close();
                remove("StuRecord.txt");
                rename("Temp.txt", "StuRecord.txt");

                if (found)
                    cout << "\nRecord deleted successfully!";
                else
                    cout << "\nRecord not found!";
                break;
            }

            case 8:
                cout << "\n\tThank you for using the program!";
                break;

            default:
                cout << "\nInvalid choice! Try again.";
        }
    } while (choice != 8);

    return 0;
}
