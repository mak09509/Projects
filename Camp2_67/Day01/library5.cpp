#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

struct Runner {
    string name;
    int time;
};
struct CompareRunners {
    bool operator()(const Runner& a, const Runner& b) const {
        return a.time < b.time;
    }
};

int main(void) {
    set<Runner, CompareRunners> runners;

    while (true) {
        string tName; int tTime; int sum = 0; cin >> tName;
        if (tName == "-") break;
        cin >> tTime; sum += tTime*3600;
        cin >> tTime; sum += tTime*60;
        cin >> tTime; sum += tTime;
        runners.emplace(Runner{tName, sum});
    }

    for (auto& it : runners) {
        cout << it.name << " ";
    }
    return 0;
}
