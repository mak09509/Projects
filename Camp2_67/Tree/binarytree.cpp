#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node *sibling;
    int depth;
    int degree;
    int height;
    char type;
    Node (int p) {
        data = p;
        left = nullptr; right = nullptr; parent = nullptr; sibling = nullptr;
        depth = 0; degree = 0; type = 'l'; height = 0;
    }
};

class BinaryTree {
public:
    Node *root;
    unordered_map<int, Node*> mapper;
    int n;
    int getNodeHeight(Node *curr, int height) {
        if (curr == nullptr) return -1;
        int leftHeight = getNodeHeight(curr->left, height);
        int rightHeight = getNodeHeight(curr->right, height);
        return 1 + max(leftHeight, rightHeight);
    }

    void insert(int value, int left, int right) {
        if (root == nullptr) {
            Node *new_root = new Node(value);
            mapper[value] = new_root;
            Node *new_left = nullptr;
            Node *new_right = nullptr;
            if (left != -1) {
                new_left = new Node(left);
                mapper[left] = new_left;
                (new_root->degree)++;
                new_left->depth = new_root->depth + 1;
                new_left->parent = new_root;
            }
            if (right != -1) {
                new_right = new Node(right);
                mapper[right] = new_right;
                new_right->depth = new_root->depth + 1;
                (new_root->degree)++;
                new_right->parent = new_root;
            }
            if (left != -1) {
                new_left->sibling = new_right;
            }
            if (right != -1) {
                new_right->sibling = new_left;
            }
            root = new_root;
            new_root->left = new_left;
            new_root->right = new_right;
            new_root->depth = 0;
            new_root->type = 'r';
            return;
        } else {
            Node *new_left = nullptr;
            Node *new_right = nullptr;
            Node *curr = mapper.at(value);
            if (left != -1) {
                new_left = new Node(left);
                mapper[left] = new_left;
                new_left->parent = curr;
                new_left->depth = curr->depth + 1;
                (curr->degree)++;
                curr->type = 'i';
            }
            if (right != -1) {
                new_right = new Node(right);
                mapper[right] = new_right;
                new_right->parent = curr;
                new_right->depth = curr->depth + 1;
                (curr->degree)++;
                curr->type = 'i';
            }
            if (left != -1) {
                new_left->sibling = new_right;
            }
            if (right != -1) {
                new_right->sibling = new_left;
            }
            curr->left = new_left;
            curr->right = new_right;
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            auto it = mapper.at(i);
            int local_parent = (it->parent == nullptr) ? -1 : it->parent->data;
            int local_sibling = (it->sibling == nullptr) ? -1 : it->sibling->data;
            cout << "node " <<  i << ": ";
            cout << "parent = " << local_parent << ", ";
            cout << "sibling = " << local_sibling << ", ";
            cout << "degree = " << it->degree << ", ";
            cout << "depth = " << it->depth << ", ";
            cout << "height = " << getNodeHeight(it, 0) << ", ";
            switch (it->type) {
                case 'r':
                    cout << "root";
                    break;
                case 'l':
                    cout << "leaf";
                    break;
                case 'i':
                    cout << "internal node";
                    break;
                
            }
            cout << endl;
        }
    }

    BinaryTree(int n) {
        this->n = n;
        root = nullptr;
        mapper.reserve(n+2);
    }
};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    BinaryTree bt(n);

    int value, left, right;
    for (int i = 0; i < n; i++) {
        cin >> value >> left >> right;
        bt.insert(value, left, right);
    }

    bt.display();
    return 0;
}
