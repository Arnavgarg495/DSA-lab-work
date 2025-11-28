#include <iostream>
using namespace std;

// ====================== CIRCULAR LINKED LIST ======================
class CNode {
public:
    int data;
    CNode *next;

    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    CNode *head;

    CircularLinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        CNode *newNode = new CNode(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode *temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        CNode *newNode = new CNode(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // Insert after a specific node
    void insertAfter(int key, int val) {
        if (head == NULL) return;

        CNode *temp = head;
        do {
            if (temp->data == key) {
                CNode *newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Key not found!\n";
    }

    // Insert before a specific node
    void insertBefore(int key, int val) {
        if (head == NULL) return;

        CNode *temp = head;
        CNode *prev = NULL;

        do {
            if (temp->data == key) {
                if (temp == head) {
                    insertAtBeginning(val);
                    return;
                }
                CNode *newNode = new CNode(val);
                newNode->next = temp;
                prev->next = newNode;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Key not found!\n";
    }

    // Delete a node
    void deleteNode(int key) {
        if (head == NULL) return;

        CNode *temp = head;
        CNode *prev = NULL;

        do {
            if (temp->data == key) {
                if (temp == head) {
                    // deleting head
                    CNode *last = head;
                    while (last->next != head)
                        last = last->next;

                    if (head == last) {
                        delete head;
                        head = NULL;
                        return;
                    }

                    last->next = head->next;
                    head = head->next;
                    delete temp;
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node not found!\n";
    }

    // Search
    bool searchNode(int key) {
        if (head == NULL) return false;

        CNode *temp = head;
        do {
            if (temp->data == key)
                return true;
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Display
    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        CNode *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


// ====================== DOUBLY LINKED LIST ======================
class DNode {
public:
    int data;
    DNode *next;
    DNode *prev;

    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    DNode *head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        DNode *newNode = new DNode(val);
        if (head != NULL)
            head->prev = newNode;

        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        DNode *newNode = new DNode(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        DNode *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert after key
    void insertAfter(int key, int val) {
        DNode *temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                DNode *newNode = new DNode(val);
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != NULL)
                    temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found!\n";
    }

    // Insert before key
    void insertBefore(int key, int val) {
        if (head == NULL) return;

        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }

        DNode *temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                DNode *newNode = new DNode(val);
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found!\n";
    }

    // Delete node
    void deleteNode(int key) {
        if (head == NULL) return;

        DNode *temp = head;

        while (temp != NULL) {
            if (temp->data == key) {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next != NULL)
                    temp->next->prev = temp->prev;

                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found!\n";
    }

    // Search
    bool searchNode(int key) {
        DNode *temp = head;
        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display
    void display() {
        DNode *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


// ====================== MENU DRIVEN MAIN ======================
int main() {
    CircularLinkedList CLL;
    DoublyLinkedList DLL;
    int choice, listType, val, key;

    while (true) {
        cout << "\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 3) break;

        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Insert Before\n5. Delete Node\n6. Search Node\n7. Display List\n8. Back\nEnter operation: ";
        cin >> listType;

        if (listType == 8) continue;

        cout << "Enter value/key if needed:\n";
        switch (listType) {
        case 1:
            cout << "Value: "; cin >> val;
            (choice == 1) ? CLL.insertAtBeginning(val) : DLL.insertAtBeginning(val);
            break;

        case 2:
            cout << "Value: "; cin >> val;
            (choice == 1) ? CLL.insertAtEnd(val) : DLL.insertAtEnd(val);
            break;

        case 3:
            cout << "Insert value: "; cin >> val;
            cout << "After key: "; cin >> key;
            (choice == 1) ? CLL.insertAfter(key, val) : DLL.insertAfter(key, val);
            break;

        case 4:
            cout << "Insert value: "; cin >> val;
            cout << "Before key: "; cin >> key;
            (choice == 1) ? CLL.insertBefore(key, val) : DLL.insertBefore(key, val);
            break;

        case 5:
            cout << "Delete key: "; cin >> key;
            (choice == 1) ? CLL.deleteNode(key) : DLL.deleteNode(key);
            break;

        case 6:
            cout << "Search key: "; cin >> key;
           
            break;

        case 7:
            (choice == 1) ? CLL.display() : DLL.display();
            break;
        }
    }

    return 0;
}
