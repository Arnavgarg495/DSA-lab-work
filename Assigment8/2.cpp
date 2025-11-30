#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left,*right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}


Node* searchRec(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}


Node* searchNonRec(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}


Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}


Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}


Node* inorderSuccessor(Node* root, int key) {
    Node* curr = searchNonRec(root, key);
    if (curr == nullptr) return nullptr;

   
    if (curr->right != nullptr)
        return findMin(curr->right);

   
    Node* succ = nullptr;
    Node* ancestor = root;

    while (ancestor != curr) {
        if (curr->data < ancestor->data) {
            succ = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return succ;
}


Node* inorderPredecessor(Node* root, int key) {
    Node* curr = searchNonRec(root, key);
    if (curr == nullptr) return nullptr;

  
    if (curr->left != nullptr)
        return findMax(curr->left);

   
    Node* pred = nullptr;
    Node* ancestor = root;

    while (ancestor != curr) {
        if (curr->data > ancestor->data) {
            pred = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return pred;
}


void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = nullptr;

    
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    cout << "In-order Traversal: ";
    inorder(root);

    
    cout << "\nSearch (Recursive) 15: " 
         << (searchRec(root, 15) ? "Found" : "Not Found");

    cout << "\nSearch (Non-Recursive) 25: " 
         << (searchNonRec(root, 25) ? "Found" : "Not Found");

   
    cout << "\nMinimum: " << findMin(root)->data;
    cout << "\nMaximum: " << findMax(root)->data;

   
    Node* suc = inorderSuccessor(root, 15);
    cout << "\nSuccessor of 15: " << (suc ? to_string(suc->data) : "None");

    Node* pre = inorderPredecessor(root, 15);
    cout << "\nPredecessor of 15: " << (pre ? to_string(pre->data) : "None");

    return 0;
}
