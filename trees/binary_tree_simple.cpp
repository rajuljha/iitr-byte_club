#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node in heap
Node* CreateNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node in heap
Node* CreateNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert nodes in level order
Node* InsertNode(Node* root, int data) {
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    int choice;
    cout << "Enter 1 to insert in left node or 2 to insert in right node of " << root->data << ": ";
    cin >> choice;
    if (choice == 1)
        root->left = InsertNode(root->left, data);
    else
        root->right = InsertNode(root->right, data);

    return root;
}

// Function to print the tree in in-order traversal
void printInOrder(Node* temp) {
    if (temp == NULL)
        return;

    printInOrder(temp->left);
    cout << temp->data << ' ';
    printInOrder(temp->right);
}

int main() {
    Node* root = NULL;
    int data;
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter data for node " << i+1 << ": ";
        cin >> data;
        if(i == 0) {
            root = InsertNode(root, data); // First data will be root node
        } else {
            InsertNode(root, data);
        }
    }

    printInOrder(root);

    return 0;
}