#include <bits/stdc++.h>
using namespace std;

int main(void) {
    deque<int> dq; string temp;

    while (cin >> temp) {
        if (temp[0] == 'S') break;

        if (temp[0] == 'E') {
            dq.push_front(dq.back());
            dq.pop_back();
            continue;
        }
        dq.push_back(stoi(temp));
    }

    for (auto it : dq) {
        cout << it << " ";
    }

    return 0;
}
