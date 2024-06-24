#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void insert(int data) {
        if (root == NULL) {
            root = new Node(data);
        } else {
            insertNode(root, data);
        }
    }

    void insertNode(Node* node, int data) {
        if (data < node->data) {
            if (node->left == NULL) {
                node->left = new Node(data);
            } else {
                insertNode(node->left, data);
            }
        } else {
            if (node->right == NULL) {
                node->right = new Node(data);
            } else {
                insertNode(node->right, data);
            }
        }
    }

    void printInOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    }

    void printPreOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }

    void printPostOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << " ";
    }

    void display(Node* node, int level) {
        if (node == NULL) {
            return;
        }
        display(node->right, level + 1);
        cout << endl;
        if (node == root) {
            cout << "Root -> ";
        }
        for (int i = 0; i < level && node != root; i++) {
            cout << "        ";
        }
        cout << node->data;
        display(node->left, level + 1);
    }

    Node* deleteNode(Node* node, int key) {
        if (node == NULL) {
            return node;
        }
        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
};


int main() {
    BinaryTree tree;
    int choice, data;
    do {
        cout << "Enter your choice:\n1. Insert\n2. Delete\n3. Display Inorder\n4. Display Preorder\n5. Display Postorder\n6. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Enter data to delete: ";
                cin >> data;
                tree.deleteNode(tree.root, data);
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.printInOrder(tree.root);
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal: ";
                tree.printPreOrder(tree.root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal: ";
                tree.printPostOrder(tree.root);
                cout << endl;
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
