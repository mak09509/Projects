#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> arr; arr.resize(n);
    for (auto& it : arr) cin >> it;
    vector<int> res; res.assign(n, -1);

    stack<int> stk;
    for (int i = n-1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            res[i] = stk.top();
        }
        stk.push(arr[i]);
    }
    for (int i = n-1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            res[i] = stk.top();
        }
        stk.push(arr[i]);
    }

    for (auto it : res) {
        cout << it << " ";
    }

    return 0;
}
