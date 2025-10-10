#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int n; cin >> n;
    vector<int> arr; arr.resize(n);
    for (auto& it : arr) cin >> it;
    
    stack<int> stk; int count = 0;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.top() < arr[i]) {
            stk.pop();
        }
        count += stk.size();
        stk.push(arr[i]);
    }
    cout << count;
    return 0;
}


