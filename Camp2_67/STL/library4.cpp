#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

struct Student {
    string name;
    char grade;
    int score;
};
struct CompareStudent {
    bool operator()(const Student& a, const Student& b) const {
        return a.score > b.score;
    }
};

int main(void) {
    set<Student, CompareStudent> student;
    string tname;
    char tgrade;
    int tscore;

    while (cin >> tname && cin >> tgrade && cin >> tscore) {
        if (tgrade == '-') break;
        student.emplace(Student{tname, tgrade, tscore});
    }

    for (auto& it : student) {
        cout << it.name << " " << it.grade << " " << it.score << endl;
    }
    return 0;
}













