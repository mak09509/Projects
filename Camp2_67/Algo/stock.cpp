#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> arr; arr.resize(n);
    vector<int> res; res.resize(n);
    for (auto& it : arr) cin >> it;

    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[stk.top()] < arr[i]) {
            stk.pop();
        }

        if (stk.empty()) {
            res[i] = i + 1;
        } 
        else {
            res[i] = i - stk.top();
        }

        stk.push(i);
    }

    for (auto it : res) {
        cout << it << " ";
    }

    return 0;
}
