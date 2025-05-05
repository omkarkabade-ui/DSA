#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
    int lbit, rbit;
};

class tbt {
    node *head, *temp;
    
public:
    tbt() {
        head = new node();
        head->left = head;
        head->right = head;
        head->lbit = 0;
        head->rbit = 1;
    }
    
    node* create();
    void insert();
    node* inpre(node*);
    node* insuc(node*);
    void display();
    void inorder(node*);
    void displayThreadedNodes();
    void showThreads(node*);
};

node* tbt::create() {
    node* p = new node();
    p->left = p->right = nullptr;
    p->lbit = p->rbit = 0;
    cout << "\nEnter the data: ";
    cin >> p->data;
    return p;
}

void tbt::insert() {
    temp = create();
    if (head->left == head) { 
        head->left = temp;
        temp->left = head;
        temp->right = head;
        temp->lbit = temp->rbit = 0;
        head->lbit = 1;
    } else {
        node *t1 = head->left, *s = nullptr;
        
        while (t1 != nullptr) {
            s = t1;
            if (temp->data > t1->data) {
                if (t1->rbit == 1)
                    t1 = t1->right;
                else
                    break;
            } else {
                if (t1->lbit == 1)
                    t1 = t1->left;
                else
                    break;
            }
        }

        if (temp->data > s->data) {
            s->right = temp;
            s->rbit = 1;
        } else {
            s->left = temp;
            s->lbit = 1;
        }

        temp->left = inpre(head->left);
        temp->right = insuc(head->left);
    }
}

node* tbt::inpre(node* m) {
    node* t = nullptr;
    while (m->lbit == 1)
        m = m->left;
    return m;
}

node* tbt::insuc(node* m) {
    node* t = nullptr;
    while (m->rbit == 1)
        m = m->right;
    return m;
}

void tbt::display() {
    if (head->left == head) {
        cout << "\nTree is empty.";
        return;
    }
    inorder(head->left);
}

void tbt::inorder(node* m) {
    if (m->lbit == 1)
        inorder(m->left);
    cout << "\n" << m->data;
    if (m->rbit == 1)
        inorder(m->right);
}

void tbt::displayThreadedNodes() {
    cout << "\nThreaded Nodes:";
    showThreads(head->left);
}

void tbt::showThreads(node* m) {
    if (m->lbit == 1)
        showThreads(m->left);
    if (m->lbit == 0 || m->rbit == 0)
        cout << "\n" << m->data;
    if (m->rbit == 1)
        showThreads(m->right);
}

int main() {
    tbt tree;
    int ch;
    while (true) {
        cout << "\n1. Insert Data";
        cout << "\n2. Display Inorder";
        cout << "\n3. Display Threaded Nodes";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                tree.insert();
                break;
            case 2:
                tree.display();
                break;
            case 3:
                tree.displayThreadedNodes();
                break;
            case 4:
                exit(0);
            default:
                cout << "\nInvalid choice!";
        }
    }
    return 0;
}
