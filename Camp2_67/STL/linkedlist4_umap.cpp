#include <bits/stdc++.h>
using namespace std;
#define ll long long

list<int> l;
unordered_map<int, list<int>::iterator> pos;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char op;
    while (cin >> op) {
        if (op == 'a') {
            int X, Y; cin >> X >> Y;
            if (pos.count(X)) continue;
            
            if (!pos.count(Y)) {
                l.push_back(X);
                pos[X] = prev(l.end());
            } else {
                pos[X] = l.insert(pos[Y], X);
            }
        }
        else if (op == 'r') {
            int I; cin >> I;
            if (I < l.size()) {
                auto it = next(l.begin(), I);
                auto val = *it;
                l.erase(it);
                pos.erase(val);
            } else continue;
        }
        else if (op == 'p') {
            for (auto it : l) cout << it << " ";
            if (l.size() > 0) cout << '\n';
        }
        else if (op == 'e') break;
    }
    return 0;
}
