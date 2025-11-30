#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    cout << "Pre-order: ";
    preorder(root);

    cout << "\nIn-order: ";
    inorder(root);

    cout << "\nPost-order: ";
    postorder(root);

    return 0;
}
