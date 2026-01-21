#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

/* Insert at beginning */
void insertBegin(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = head;
    head = n;
}

/* Insert at end */
void insertEnd(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

/* Delete from beginning */
void deleteBegin() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

/* Delete from end */
void deleteEnd() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

/* Display */
void display() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/* Main */
int main() {
    int ch, val;

    do {
        cout << "\n1.Insert Begin\n2.Insert End\n3.Delete Begin\n4.Delete End\n5.Display\n6.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBegin(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(val);
                break;

            case 3:
                deleteBegin();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 6);

    return 0;
}