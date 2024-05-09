#include <iostream>
#include <vector>

using std::cout; using std::vector;
using std::endl; using std::string;

struct BSTreeNode {
    string key;
    struct BSTreeNode *left{};
    struct BSTreeNode *right{};
};

void insertNode(BSTreeNode *&root, const string& k) {
    if (root == nullptr) {
        root = new BSTreeNode;
        root->key = k;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (k < root->key)
            insertNode(root->left, k);
        else
            insertNode(root->right, k);
    }
}

void printTree(BSTreeNode *n) {
    if (n != nullptr) {
        printTree(n->left);
        cout << n->key << "; ";
        printTree(n->right);
    }
}

int main() {
    std::vector<string> v1 {"camel", "wind", "zero", "maya", "aim", "born", "xen"};

    BSTreeNode *root = nullptr;

    for (const auto &item : v1) {
        insertNode(root, item);
    }

    printTree(root);

    return EXIT_SUCCESS;
}