#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Account {
    string name;
    int balance;
};
unordered_map<string, Account> manager;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    manager.reserve(n);
    for (int i = 0; i < n; i++) {
        string tname, tpassword; int tbalance;
        cin >> tname >> tbalance >> tpassword;
        manager[tpassword] = Account{tname, tbalance};
    }

    string password; cin >> password;
    cout << manager.at(password).name << " " << manager.at(password).balance;
    return 0;
}
