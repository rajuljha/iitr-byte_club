#include <iostream>
using namespace std;

class TreeNode {
    public:
        int value;
        
        TreeNode * left;
        TreeNode * right;

        TreeNode() {
            value = 0;
            left = NULL;
            right = NULL;
        }

        TreeNode (int v) {
            value = v;
            left = NULL;
            right = NULL;
        }
};

class BST {
    public: 
        TreeNode * root;

    bool isEmpty() {
        if (root == NULL) {
            return true;
        }
        else {
            return false;
        }
    }


};

int main() {
    BST tree;
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