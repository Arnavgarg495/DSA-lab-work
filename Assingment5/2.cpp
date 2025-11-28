#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


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


int deleteAllOccurrences(int key) {
    int count = 0;

   
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }

    return count;
}

void display() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty.";
        return;
    }
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int x : arr) insertAtEnd(x);

    cout << "Original Linked List: ";
    display();

    int key = 1;

    int count = deleteAllOccurrences(key);

    cout << "Count: " << count << endl;

    cout << "Updated Linked List: ";
    display();

    return 0;
}
