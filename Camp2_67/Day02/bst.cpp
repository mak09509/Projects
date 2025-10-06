#include <bits/stdc++.h>
using namespace std;
#define ll long long

ostringstream buffer;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node (int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node *root;
    unordered_set<int> stored;
    void sysInorder(Node *curr) {
        if (curr != nullptr) {
            sysInorder(curr->left);
            buffer << curr->data << " ";
            sysInorder(curr->right);
        }
    }
    void sysPreorder(Node *curr) {
        if (curr != nullptr) {
            buffer << curr->data << " ";
            sysPreorder(curr->left);
            sysPreorder(curr->right);
        }
    }
public:
    void inorder() {
        sysInorder(root);
        buffer << endl;
    }
    void preorder() {
        sysPreorder(root);
        buffer << endl;
    }
    void insert(int value) {
        Node *new_node = new Node(value);
        if (root == nullptr) {
            root = new_node;
            stored.insert(value);
            return;
        }
        Node *parent = nullptr;
        Node *curr = root;
        while (curr != nullptr) {
            if (value < curr->data) {
                parent = curr;
                curr = curr->left;
            } else if (value > curr->data) {
                parent = curr;
                curr = curr->right;
            } else {
                return;
            }
        }
        if (value < parent->data) {
            parent->left = new_node;
        } else if (value > parent->data) {
            parent->right = new_node;
        }
        stored.insert(value);
    }
    void find(int value) {
        if (stored.find(value) != stored.end()) {
            buffer << "yes" << endl;
        } else {
            buffer << "no" << endl;
        }
    }
    BST (int n) {
        root = nullptr;
        stored.reserve(n/2);
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    BST bst(n);

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "print") {
            bst.inorder();
            bst.preorder();
        } else if (s == "find") {
            int value; cin >> value;
            bst.find(value);
        } else if (s == "insert") {
            int value; cin >> value;
            bst.insert(value);
        }
    }
    cout << buffer.str();
    return 0;
}
