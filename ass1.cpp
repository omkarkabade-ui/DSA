#include <bits/stdc++.h>
using namespace std;

struct ClientData {
    char name[30];
    long teleno;
};

class Hash1 {
public:
    static const int SIZE = 10;
    ClientData d[SIZE];

    Hash1() {
        for (int i = 0; i < SIZE; i++) {
            d[i].teleno = 0;
            strcpy(d[i].name, "");
        }
    }

    int hashFunction(const char* name) {
        int sum = 0;
        for (int i = 0; name[i] != '\0'; i++) {
            sum = sum * 31 + name[i];  // Weighted hash
        }
        return abs(sum) % SIZE;
    }

    void insert() {
        int n;
        cout << "\nEnter the number of clients: ";
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear buffer

        for (int j = 0; j < n; j++) {
            char na[30];
            long no;
            cout << "\nEnter name of client: ";
            cin.getline(na, 30);
            cout << "Enter telephone number of client: ";
            cin >> no;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear buffer

            int x = hashFunction(na);
            int c = x;
            int probes = 0;

            while (probes < SIZE) {
                if (d[x].teleno == 0) {
                    strcpy(d[x].name, na);
                    d[x].teleno = no;
                    cout << "Inserted at index " << x << endl;
                    break;
                } else if (strcmp(d[x].name, na) == 0) {
                    cout << "Duplicate name found. Skipping insert.\n";
                    break;
                }

                x = (x + 1) % SIZE;
                probes++;
            }

            if (probes == SIZE) {
                cout << "\nHash table is full. Cannot insert more data.\n";
            }
        }
    }

    void search() {
        char na[30];
        cout << "\nEnter name to be searched: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear buffer
        cin.getline(na, 30);

        int x = hashFunction(na);
        int c = x;
        int probes = 0;

        while (probes < SIZE) {
            if (strcmp(d[x].name, na) == 0) {
                cout << "\nData found: TELEPHONE NO: " << d[x].teleno << endl;
                return;
            }

            x = (x + 1) % SIZE;
            probes++;
        }

        cout << "\nData not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            if (d[i].teleno != 0) {
                cout << i << " --> " << d[i].name << " " << d[i].teleno << endl;
            } else {
                cout << i << " --> [Empty]" << endl;
            }
        }
    }
};

int main() {
    Hash1 h;
    h.insert();
    h.search();
    h.display();
    return 0;
}
