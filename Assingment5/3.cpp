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


int findMiddle() {
    if (head == NULL)
        return -1;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        
        fast = fast->next->next;     
    }

    return slow->data;  
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr)
        insertAtEnd(x);

    int mid = findMiddle();

    cout << "Middle Node: " << mid << endl;

    return 0;
}
