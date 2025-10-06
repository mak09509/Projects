#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ifstream input("output.txt");

int main(void) {
    ios::sync_with_stdio(false);
    input.tie(nullptr);

    list<int> l;
    int operation;

    while (true) {
        input >> operation;

        if (operation == 1) {
            int insertent; input >> insertent;
            int insertute; input >> insertute;

            if (find(l.begin(), l.end(), insertent) != l.end()) continue;
            auto tutepos = find(l.begin(), l.end(), insertute);

            if (tutepos == l.end()) l.push_front(insertent);
            else l.insert(std::next(tutepos, 1), insertent);
        }
        else if (operation == 0) {
            int victim; input >> victim;
            auto victimpos = find(l.begin(), l.end(), victim);
            if (victimpos != l.end() && l.size() != 1) l.erase(victimpos);
            else continue;
        }
        else if (operation == 3) break;

    }
    cout << "Finish!";
    return 0;
}
