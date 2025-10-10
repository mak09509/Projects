#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
    ios::sync_with_stdio(false);

    unordered_map<char, int> counter;
    map<char, int> ordered_storer;
    vector<char> str;
    ostringstream buffer;
    counter.reserve(32);
    str.reserve(64);

    char temp;
    while (cin.get(temp) && temp != '\n') {
        str.push_back(temp);
        (counter[temp])++;
    }
    for (auto it : str) {
        int value = counter[it];
        if (value > 1) {
            ordered_storer[it] = value;
        }
        else if (value == 1) {
            buffer << it;
        }
    }

    if (ordered_storer.empty()) {
        cout << "no" << endl;
    }
    else {
        for (auto it : ordered_storer) {
            cout << it.first << " " << it.second << endl;
        }
    }
    cout << buffer.str() << endl;
    return 0;
}
