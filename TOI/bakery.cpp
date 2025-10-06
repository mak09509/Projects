#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c, d, e; cin >> n;
    float sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d >> e;
        sum += (a*8 + b*6 + c*4 + d*2 + e);
    }

    cout << ceil(sum/8.0f);
    return 0;
}
