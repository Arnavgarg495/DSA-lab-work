#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end to build the list
void insertAtEnd(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// Reverse the linked list
void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // save next node
        curr->next = prev;   // reverse pointer
        prev = curr;         // move prev
        curr = next;         // move curr
    }

    head = prev; // new head after reversing
}

// Display linked list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    // Build list: 1->2->3->4->NULL
    int arr[] = {1, 2, 3, 4};
    for (int x : arr)
        insertAtEnd(x);

    cout << "Original List: ";
    display();

    reverseList();

    cout << "Reversed List: ";
    display();

    return 0;
}
