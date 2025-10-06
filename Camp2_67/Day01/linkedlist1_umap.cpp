#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

list<int> l;
unordered_map<int, list<int>::iterator> pos;
ifstream input("output.txt");

int main(void) {
    ios::sync_with_stdio(false);
    input.tie(nullptr);

    int op;
    while (input >> op) {
        if (op == 1) {
            int number, id; input >> number >> id;
            if (pos.count(number)) continue;
            
            if (!pos.count(id)) {
                l.push_front(number);
                pos[number] = l.begin();
            } else {
                auto it = pos[id];
                pos[number] = l.insert(next(it), number);
            }
        }

        else if (op == 0) {
            int id; input >> id;
            if (pos.count(id)) {
                l.erase(pos[id]);
                pos.erase(id);
            } else continue;
        }

        else if (op == 3) break;
    }

    cout << "Finish!";
    return 0;
}








