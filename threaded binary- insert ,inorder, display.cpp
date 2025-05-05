#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
    int lbit, rbit;
};

class tbt {
    node *temp = NULL, *t1 = NULL, *s = NULL, *head = NULL, *t = NULL;
public:
    node* create();
    void insert();
    node* insuc(node*);
    node* inpre(node*);
    void dis();
    void display(node*);
    void thr();
    void thread(node*);
};

node* tbt::create() {
    node *p = new node;
    p->left = NULL;
    p->right = NULL;
    p->lbit = 0;
    p->rbit = 0;
    cout << "\nEnter the data: ";
    cin >> p->data;
    return p;
}

void tbt::insert() {
    temp = create();
    if (head == NULL) {
        head = new node;
        head->left = temp;
        head->right = head;
        head->lbit = 1;
        head->rbit = 0;
        temp->left = head;
        temp->right = head;
        temp->lbit = 0;
        temp->rbit = 0;
    } else {
        t1 = head->left;
        while (t1 != NULL) {
            s = t1;
            if (temp->data > t1->data && t1->rbit == 1) {
                t1 = t1->right;
            } else if (temp->data < t1->data && t1->lbit == 1) {
                t1 = t1->left;
            } else {
                break;
            }
        }

        if (temp->data > s->data) {
            temp->right = s->right;
            temp->left = s;
            s->right = temp;
            s->rbit = 1;
        } else {
            temp->left = s->left;
            temp->right = s;
            s->left = temp;
            s->lbit = 1;
        }
    }
}

void tbt::dis() {
    if (head == NULL || head->left == head) {
        cout << "\nThe tree is empty.";
        return;
    }
    display(head->left);
}

void tbt::display(node *m) {
    while (m != head) {
        while (m->lbit == 1) {
            m = m->left;
        }
        cout << "\n" << m->data;
        while (m->rbit == 0) {
            m = m->right;
            if (m == head) return;
            cout << "\n" << m->data;
        }
        m = m->right;
    }
}

void tbt::thr() {
    cout << "\nThreaded nodes are:";
    thread(head->left);
}

void tbt::thread(node *m) {
    if (m == NULL || m == head) return;

    if (m->lbit == 1) thread(m->left);

    if (m->lbit == 0 || m->rbit == 0) {
        cout << "\n" << m->data;
    }

    if (m->rbit == 1) thread(m->right);
}

int main() {
    tbt t;
    int ch;
    while (1) {
        cout << "\n\nEnter your choice:";
        cout << "\n1. Insert data";
        cout << "\n2. Display all data";
        cout << "\n3. Display threaded nodes";
        cout << "\n4. Exit";
        cout << "\nChoice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            t.insert();
            break;
        case 2:
            t.dis();
            break;
        case 3:
            t.thr();
            break;
        case 4:
            exit(0);
        default:
            cout << "\nInvalid choice!";
        }
    }
    return 0;
}
