#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, v, w;
array<int, (size_t)(1e4 + 1)> a, e, o, dp; 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    a[0] = e[0] = o[0] = dp[0] = 0;
    cin >> n >> v >> w;    

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        e[i] = e[i-1] + (x&1 ? 0:x);
        o[i] = o[i-1] + (x&1 ? x:0);
    }
    memset(dp.data(), -1, sizeof dp);
    return 0;
}






















