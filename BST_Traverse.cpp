#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    TreeNode* insertRec(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }

    void preOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->value << " ";
        }
    }
};

int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(2);
    bst.insert(7);

    cout << "In-order Traversal: ";
    bst.inOrderTraversal(bst.root);  // Output: 2 5 7 10 15
    cout << endl;

    cout << "Pre-order Traversal: ";
    bst.preOrderTraversal(bst.root);  // Output: 10 5 2 7 15
    cout << endl;

    cout << "Post-order Traversal: ";
    bst.postOrderTraversal(bst.root);  // Output: 2 7 5 15 10
    cout << endl;

    return 0;
}
