#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
void insertAtBeginning(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    cout << "Inserted at beginning.\n";
}
void insertAtEnd(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        cout << "Inserted at end.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    cout << "Inserted at end.\n";
}
void insertBefore(int value, int key) {
    Node* newnode = new Node();
    newnode->data = value;

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == key) {
        newnode->next = head;
        head = newnode;
        cout << "Inserted before " << key << ".\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Key not found.\n";
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    cout << "Inserted before " << key << ".\n";
}

void insertAfter(int value, int key) {
    Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Key not found.\n";
        return;
    }

    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;

    cout << "Inserted after " << key << ".\n";
}
void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Deleted from beginning.\n";
}
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted from end.\n";
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;

    cout << "Deleted from end.\n";
}

void deleteSpecific(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node " << key << ".\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Node not found.\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Deleted node " << key << ".\n";
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position: " << pos << endl;
            return;
        }
        pos++;
        temp = temp->next;
    }

    cout << "Node not found.\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    int choice, value, key;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Insert After a Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Insert before which value? ";
            cin >> key;
            insertBefore(value, key);
            break;

        case 4:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Insert after which value? ";
            cin >> key;
            insertAfter(value, key);
            break;

        case 5:
            deleteBeginning();
            break;

        case 6:
            deleteEnd();
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteSpecific(key);
            break;

        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            searchNode(key);
            break;

        case 9:
            display();
            break;

        case 10:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}