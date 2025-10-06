#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

list<int> l;
unordered_map<int, list<int>::iterator> pos;
ostringstream buffer;

int main(void) {
    
    char op;
    while (cin >> op) {
        if (op == 'I') {
            int number, id; cin >> number >> id;
            if (pos.count(number)) continue;

            if (!pos.count(id)) {
                l.push_back(number);
                pos[number] = prev(l.end());
            } else {
                pos[number] = l.insert(pos[id], number);
            }
        }

        else if (op == 'D') {
            int id; cin >> id;
            if (pos.count(id)) {
                l.erase(pos[id]);
                pos.erase(id);
            } else continue;
        }

        else if (op == 'E') break;
        for (auto it : l) buffer << it << " ";
        buffer << endl;
    }

    cout << buffer.str();
    return 0;
}
