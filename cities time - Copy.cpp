#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct node {
    string vertex;
    int time;
    node *next;
};

class adjmatlist {
    int m[20][20], n, i, j;
    char ch;
    string v[20];
    node *head[20], *temp = NULL;

public:
    adjmatlist() {
        for (i = 0; i < 20; i++) {
            head[i] = NULL;
            for (j = 0; j < 20; j++) {
                m[i][j] = 0; // Initialize adjacency matrix
            }
        }
    }

    void getgraph();
    void adjlist();
    void displaym();
    void displaya();
};

void adjmatlist::getgraph() {
    cout << "\nEnter number of cities (max 20): ";
    cin >> n;

    if (n > 20) {
        cout << "\nNumber of cities cannot exceed 20!";
        return;
    }

    cout << "\nEnter names of cities:\n";
    for (i = 0; i < n; i++)
        cin >> v[i];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) { // Avoid self-loops unless needed
                cout << "\nIs there a path between " << v[i] << " and " << v[j] << "? (y/n): ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y') {
                    cout << "Enter time required to reach " << v[j] << " from " << v[i] << " in minutes: ";
                    cin >> m[i][j];
                } else {
                    m[i][j] = 0;
                }
            } else {
                m[i][j] = 0; // No self-loops by default
            }
        }
    }

    adjlist();
}

void adjmatlist::adjlist() {
    for (i = 0; i < n; i++) {
        node *p = new node;
        p->next = NULL;
        p->vertex = v[i];
        head[i] = p;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (m[i][j] != 0) {
                node *p = new node;
                p->vertex = v[j];
                p->time = m[i][j];
                p->next = NULL;

                if (head[i]->next == NULL) {
                    head[i]->next = p;
                } else {
                    temp = head[i];
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = p;
                }
            }
        }
    }
}

void adjmatlist::displaym() {
    cout << "\nAdjacency Matrix:\n\t";
    for (j = 0; j < n; j++) {
        cout << v[j] << "\t";
    }

    for (i = 0; i < n; i++) {
        cout << "\n" << v[i] << "\t";
        for (j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

void adjmatlist::displaya() {
    cout << "\nAdjacency List:\n";
    for (i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "\nAdjacency list not present.";
            return;
        }

        cout << "\n" << head[i]->vertex;
        temp = head[i]->next;
        while (temp != NULL) {
            cout << " -> " << temp->vertex;
            temp = temp->next;
        }
    }

    cout << "\n\nPath and Time Required to Reach Cities:\n";
    for (i = 0; i < n; i++) {
        temp = head[i]->next;
        while (temp != NULL) {
            cout << head[i]->vertex << " -> " << temp->vertex;
            cout << " [Time: " << temp->time << " min]\n";
            temp = temp->next;
        }
    }
}

int main() {
    int m;
    adjmatlist a;

    while (true) {
        cout << "\n\nEnter the choice:";
        cout << "\n1. Enter Graph";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. Display Adjacency List";
        cout << "\n4. Exit";
        cout << "\nChoice: ";
        cin >> m;

        switch (m) {
            case 1:
                a.getgraph();
                break;
            case 2:
                a.displaym();
                break;
            case 3:
                a.displaya();
                break;
            case 4:
                return 0; // Proper exit
            default:
                cout << "\nUnknown choice!";
        }
    }

    return 0;
}
