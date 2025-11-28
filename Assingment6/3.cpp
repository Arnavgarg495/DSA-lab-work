#include <iostream>
using namespace std;
// 1
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

Node* head = NULL;


void insertAtEnd(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head =newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


int sizeOfDoublyList() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    cout << "Size of Doubly Linked List = " << sizeOfDoublyList();
    return 0;
}

// 2

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head2 = NULL;


void insertCircular(int val) {
    Node* newNode = new Node(val);

    if (head2 == NULL) {
        head2 = newNode;
        newNode->next = head2;
        return;
    }

    Node* temp = head2;
    while (temp->next != head2)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head2;
}


int sizeOfCircularList() {
    if (head2 == NULL)
        return 0;

    int count = 0;
    Node* temp = head2;

    do {
        count++;
        temp = temp->next;
    } while (temp != head2);

    return count;
}

int main() {
    insertCircular(5);
    insertCircular(15);
    insertCircular(25);
    insertCircular(35);

    cout << "Size of Circular Linked List = " 
         << sizeOfCircularList();

    return 0;
}
