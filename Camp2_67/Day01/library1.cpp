#include <bits/stdc++.h>

using namespace std;

int main(void) {
    char temp, state = 0;
    while ((temp = getchar()) != '\n') {
        if (temp == 'n') state++;
        if (temp == 's') state--;
    }
    if (state == 0) cout << "OK";
    else cout << "ERR";
    return 0;
}
