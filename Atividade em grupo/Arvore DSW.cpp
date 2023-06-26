#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

Node* DSWBalance(Node* root) {
    Node dummy(0);
    dummy.right = root;
    Node* current = &dummy;

    while (current != nullptr) {
        if (current->left != nullptr) {
            Node* subroot = rotateRight(current);
            current = subroot->right;
        } else {
            current = current->right;
        }
    }

    int n = 0;
    current = dummy.right;

    while (current != nullptr) {
        current = rotateRight(current);
        if (n % 2 == 0) {
            dummy.right = current;
        }
        current = current->right;
        n++;
    }

    int m = n + 1 - pow(2, floor(log2(n + 1)));
    Node* currRoot = dummy.right;
    Node* prev = nullptr;

    while (m > 1) {
        currRoot = rotateRight(currRoot);
        m = m / 2;
        prev = currRoot->right;
        for (int i = 0; i < m; i++) {
            prev = rotateRight(prev);
            prev = prev->right;
        }
    }

    return dummy.right;
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    cout << "�rvore antes do balanceamento DSW: ";
    inOrderTraversal(root);
    cout << endl;

    root = DSWBalance(root);

    cout << "�rvore ap�s o balanceamento DSW: ";
    inOrderTraversal(root);
    cout << endl;

����return�0;
}
