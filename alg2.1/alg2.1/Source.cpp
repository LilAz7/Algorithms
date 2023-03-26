#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int left_height = getHeight(node->left);
        int right_height = getHeight(node->right);
        return max(left_height, right_height) + 1;
    }

    int getBalanceFactor(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int left_height = getHeight(node->left);
        int right_height = getHeight(node->right);
        return left_height - right_height;
    }

    Node* insertHelper(Node* node, int value) {
        if (node == NULL) {
            node = new Node;
            node->value = value;
            node->left = NULL;
            node->right = NULL;
        }
        else if (value < node->value) {
            node->left = insertHelper(node->left, value);
        }
        else {
            node->right = insertHelper(node->right, value);
        }
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) > 0) {
                node = rotateRight(node);
            }
            else {
                node->left = rotateLeft(node->left);
                node = rotateRight(node);
            }
        }
        else if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) < 0) {
                node = rotateLeft(node);
            }
            else {
                node->right = rotateRight(node->right);
                node = rotateLeft(node);
            }
        }
        return node;
    }

    Node* rotateRight(Node* node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }

    Node* rotateLeft(Node* node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }

public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void printBalanceFactors() {
        printHelper(root);
    }

    void printHelper(Node* node) {
        if (node != NULL) {
            printHelper(node->left);
            cout << "Node " << node->value << " has a balance factor of " << getBalanceFactor(node) << endl;
            printHelper(node->right);
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(4);
    bst.insert(7);
    bst.insert(14);
    bst.insert(13);
    bst.printBalanceFactors();
    return 0;
}