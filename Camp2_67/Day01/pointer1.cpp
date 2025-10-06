#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n; set<int> s;
int rmin = INT_MAX, rmax = INT_MIN;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        s.emplace(temp);
        rmin = min(rmin, temp);
        rmax = max(rmax, temp);
    }

    int op; cin >> op;
    if (op == 1) {
        for (auto it : s) cout << it << endl;
    }
    else if (op == 2) {
        cout << rmax << endl;
    }
    else if (op == 3) {
        cout << rmin << endl;
    }
    return 0;
}
