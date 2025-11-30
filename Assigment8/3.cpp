#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert (No duplicates)
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Find minimum node
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Delete node
Node* deleteNode(Node* root,int key) {
    if (root == nullptr) return root;

    if (key < root->data)
        root->left =deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {  
        
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Maximum depth
int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int minDepth(Node* root) {
    if (root == nullptr) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder: ";
    inorder(root);

    root = deleteNode(root, 40);
     cout << "\nAfter deleting 40: ";
    inorder(root);

    cout << "\nMaximum Depth = " << maxDepth(root);
    cout << "\nMinimum Depth = " << minDepth(root);

    return 0;
}
