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
    auto currAcc = manager.at(password);
    cout << currAcc.name << " " << currAcc.balance << endl;

    int op;
    while (cin >> op) {
        if (op == 1) {
            int deposit; cin >> deposit;
            currAcc.balance += deposit;
        }
        else if (op == 2) {
            int withdraw; cin >> withdraw;
            currAcc.balance -= withdraw;
        }
        else if (op == 3) cout << currAcc.balance << endl;
        else if (op == 4) break;
    }
    return 0;
}
