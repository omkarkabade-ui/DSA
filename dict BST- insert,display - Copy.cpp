//experiment 9
#include <iostream>
#include <cstring>

using namespace std;

struct node {
    char k[20];
    char m[100]; // Increased size for longer meanings
    node *left;
    node *right;
};

class dict {
public:
    node *root;

    dict() { root = NULL; } 

    void create();
    void disp(node *);
    void insert(node *root, node *temp);
    int search(node *, char []);
    int update(node *, char []);
    node* del(node *, char []);
    node *min(node *);
};

void dict::create() {
    node *temp;
    int ch;

    do {
        temp = new node;
        cout << "\nEnter Keyword: ";
        cin >> ws; // Clears whitespace
        cin.getline(temp->k, 20);
        cout << "Enter Meaning: ";
        cin.getline(temp->m, 100);

        temp->left = NULL;
        temp->right = NULL;

        if (root == NULL) {
            root = temp;
        } else {
            insert(root, temp);
        }

        cout << "Do you want to add more (y=1/n=0): ";
        cin >> ch;
    } while (ch == 1);
}

void dict::insert(node *root, node *temp) {
    if (strcmp(temp->k, root->k) < 0) {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    } else if (strcmp(temp->k, root->k) > 0) {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    } else {
        cout << "Keyword already exists. Ignoring duplicate.\n";
        delete temp;
    }
}

void dict::disp(node *root) {
    if (root != NULL) {
        disp(root->left);
        cout << "\nKeyword: " << root->k;
        cout << "\tMeaning: " << root->m;
        disp(root->right);
    }
}

int dict::search(node *root, char k[20]) {
    int c = 0;
    while (root != NULL) {
        c++;
        if (strcmp(k, root->k) == 0) {
            cout << "\nNo of Comparisons: " << c;
            return 1;
        }
        if (strcmp(k, root->k) < 0)
            root = root->left;
        else
            root = root->right;
    }
    return -1;
}

int dict::update(node *root, char k[20]) {
    while (root != NULL) {
        if (strcmp(k, root->k) == 0) {
            cout << "\nEnter New Meaning for " << root->k << ": ";
            cin.ignore();
            cin.getline(root->m, 100);
            return 1;
        }
        if (strcmp(k, root->k) < 0)
            root = root->left;
        else
            root = root->right;
    }
    return -1;
}

node* dict::del(node *root, char k[20]) {
    if (root == NULL) {
        cout << "\nElement Not Found";
        return root;
    }

    if (strcmp(k, root->k) < 0) {
        root->left = del(root->left, k);
    } else if (strcmp(k, root->k) > 0) {
        root->right = del(root->right, k);
    } else {
        if (root->left == NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *temp = min(root->right);
        strcpy(root->k, temp->k);
        strcpy(root->m, temp->m);
        root->right = del(root->right, temp->k);
    }
    return root;
}

node* dict::min(node *q) {
    while (q->left != NULL) {
        q = q->left;
    }
    return q;
}

int main() {
    int ch;
    dict d;

    do {
        cout << "\nMenu\n1. Create\n2. Display\n3. Search\n4. Update\n5. Delete\n6. Exit\nEnter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                d.create();
                break;
            case 2:
                if (d.root == NULL) {
                    cout << "\nNo Keywords in Dictionary";
                } else {
                    d.disp(d.root);
                }
                break;
            case 3:
                if (d.root == NULL) {
                    cout << "\nDictionary is Empty.";
                } else {
                    cout << "\nEnter Keyword to Search: ";
                    char k[20];
                    cin >> ws;
                    cin.getline(k, 20);
                    if (d.search(d.root, k) == 1)
                        cout << "\nKeyword Found";
                    else
                        cout << "\nKeyword Not Found";
                }
                break;
            case 4:
                if (d.root == NULL) {
                    cout << "\nDictionary is Empty.";
                } else {
                    cout << "\nEnter Keyword to Update: ";
                    char k[20];
                    cin >> ws;
                    cin.getline(k, 20);
                    if (d.update(d.root, k) == 1)
                        cout << "\nMeaning Updated";
                    else
                        cout << "\nKeyword Not Found";
                }
                break;
            case 5:
                if (d.root == NULL) {
                    cout << "\nDictionary is Empty.";
                } else {
                    cout << "\nEnter Keyword to Delete: ";
                    char k[20];
                    cin >> ws;
                    cin.getline(k, 20);
                    d.root = d.del(d.root, k);
                    cout << "\nKeyword Deleted (if found).";
                }
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "\nInvalid Choice";
        }
    } while (ch != 6);

    return 0;
}
