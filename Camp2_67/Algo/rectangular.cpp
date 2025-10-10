#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> arr; arr.resize(n);
    for (auto& it : arr) cin >> it;
    int res = INT_MIN;

    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        for (int j = i-1; j >= 0 && arr[j] >= arr[i]; j--) {
            curr += arr[i];
        }
        for (int j = i+1; j < n && arr[j] >= arr[i]; j++) {
            curr += arr[i];
        }
        res = max(res, curr);
    }

    cout << res;

    return 0;
}
