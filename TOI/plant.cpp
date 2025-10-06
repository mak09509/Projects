#include <bits/stdc++.h>
using namespace std;

int N, A, B;
typedef struct Plant { int H, R; } Plant;
vector<Plant> selectedCombination;
vector<Plant> allCombination;



int main(void) {
    cin >> N >> A >> B;    
    allCombination.resize(N);
    for (auto &it : allCombination) cin >> it.H >> it.R;

    return 0;
}
