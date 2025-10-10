#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int p): data(p), left(nullptr), right(nullptr) {}
};

int n;
Node *root;
vector<int> preorder;
unordered_map<int, int> inorder;
int curr = 0;

Node* buildBT(int start, int stop) {
    if (start > stop) return nullptr;
    
    Node *new_node = new Node(preorder[curr]);
    int order = inorder.at(preorder[curr++]);

    new_node->left = buildBT(start, order-1);
    new_node->right = buildBT(order+1, stop);
    return new_node;
}

void postorder(Node *curr) {
    if (curr != nullptr) {
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    preorder.resize(n);
    for (auto& it : preorder) cin >> it;

    inorder.reserve(n);
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        inorder[temp] = i;
    }

    root = buildBT(0, n-1);

    postorder(root);
    return 0;
}
