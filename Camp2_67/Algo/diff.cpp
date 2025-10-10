#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    unordered_set<int> dupe;
    int sum = 0; int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if (dupe.find(temp) == dupe.end()) {
            sum += temp;
            dupe.insert(temp);
        }
    }
    cout << sum;
    return 0;
}
