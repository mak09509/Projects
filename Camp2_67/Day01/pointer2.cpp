#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string name; int score;
string max_name, min_name;
int max_score = INT_MIN,  min_score = INT_MAX; 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum = 0; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        if (max_score < score) {
            max_score = score;
            max_name = name;
        }
        if (min_score > score) {
            min_score = score;
            min_name = name;
        }
        sum += score;
    }
    cout << max_name << endl << min_name << endl;
    cout << fixed << setprecision(4) << static_cast<float>(sum) / n;
    return 0;
}
 
