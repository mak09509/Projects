#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

unordered_map<int, stack<int>> manager;
int n, q;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q; manager.reserve(n); 

    for (int i = 0; i < q; i++) {
        int op; cin >> op;

        if (op == 0) {
            int S_t, val; cin >> S_t >> val;
            manager[S_t].push(val);
        }
        if (op == 1) {
            int S_t; cin >> S_t;
            cout << manager.at(S_t).top() << endl;
        }
        if (op == 2) {
            int S_t; cin >> S_t;
            manager.at(S_t).pop();
        }
    }
    return 0;
}

