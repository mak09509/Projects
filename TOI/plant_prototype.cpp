#include <bits/stdc++.h>
using namespace std;

/*
 *  brute force approach
 */

int N, A, B;
vector<int> H, R;
int Q = INT_MIN;

int Rsummer(int start, int stop) {
    int sum = 0;
    for (int i = start; i <= stop; i++) {
        sum += R[i];
    }
    return sum;
}

int leastDiffofH(int start, int stop) {
    int leastDiff = INT_MAX;
    for (int i = start; i < stop; i++) {
        for (int j = i+1; j <= stop; j++) {
            leastDiff = min(leastDiff, abs(H[i] - H[j]));
        }
    }
    return leastDiff;
}

int main(void) {

    cin >> N >> A >> B;
    H.resize(N); R.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> H[i] >> R[i];
    }

    for (int i = 0; i < N; i++) {
        int diffH = 0; int Rsum = 0;
        for (int j = i+1; j < N; j++) {
            Rsum = Rsummer(i, j);
            diffH = leastDiffofH(i, j);
            Q = max(Q, A*(Rsum) - B*(diffH));
            cout << diffH << " " << Rsum << " " << Q << endl;
        }
    }

    cout << Q;
    return 0;
}
