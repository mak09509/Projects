#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int n; cin >> n; int count = 0;
    vector<int> building; building.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> building[i];
    }
    
    for (int i = 0; i < n-2; i++) {
        for (int j = i+2; j < n; j++) {
            bool state = true;
            for (int k = i+1; k < j; k++) {
                if (building[k] > building[i] || building[k] > building[j]) {
                    state = false;
                    break;
                }
            }
            if (state) count++;
        }
    }

    cout << count+n-1;
    return 0;
}

