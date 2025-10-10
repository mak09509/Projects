#include <bits/stdc++.h>
using namespace std;

int main(void) {

    multiset<int> s; int temp;
    while (cin >> temp) {
        if (temp == 0) break;
        s.emplace(temp);
    }

    for (auto it : s) {
        cout << it << " ";
    }
    
    return 0;
}
