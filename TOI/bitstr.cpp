// Topic:   Top-down DP on bitmask
// File:    archive/toi/20/toi20_bit_string

#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> weight;
vector<int> dp;
vector<bool> vis;

int solve(int mask) {
    if (vis[mask]) return dp[mask];
    vis[mask] = true;
    int best = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) {
            int next = mask & ~(1 << i);
            best = max(best, solve(next));
        }
    }
    for (int i = 0; i < N-1; i++) {
        if ((mask & (1 << i)) && (mask & (1 << (i+1)))) {
            int next = mask & ~(3 << i);
            best = max(best, solve(next));
        }
    }
    dp[mask] = weight[mask] + best;
    return dp[mask];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    int total = 1 << N;
    weight.assign(total, 0);
    dp.assign(total, 0);
    vis.assign(total, 0);

    for (int i = 0; i < total; i++) {
        string s;
        int c;
        cin >> s >> c;
        int mask = 0;
        for (int j = 0; j < N; j++) {
            if (s[j] == '1') mask |= (1 << j);
        }
        weight[mask] = c;
    }
    vis[0] = true;
    dp[0b000] = weight[0b000];

    while (Q--) {
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < N; j++) {
            if (s[j] == '1') mask |= (1 << j);
        }
        cout << solve(mask) << '\n';
    }

    return 0;
}
