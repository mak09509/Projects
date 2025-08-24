// Topic:   Data structure
// File:    archive/toi/20/toi20_lover

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    array<pair<int, array<int, 5>>, 9> reference = {{
        {100,   {0, 0, 0, 0, 1}},   //C
        {90,    {0, 0, 1, 0, 1}},   //XC
        {50,    {0, 0, 0, 1, 0}},   //L
        {40,    {0, 0, 1, 1, 0}},   //XL
        {10,    {0, 0, 1, 0, 0}},   //X
        {9,    {1, 0, 1, 0, 0}},   //IX
        {5,     {0, 1, 0, 0, 0}},   //V
        {4,     {1, 1, 0, 0, 0}},   //IV
        {1,     {1, 0, 0, 0, 0}}    //I
    }};
    int n; cin >> n;
    array<int, 5> roman = {0, 0, 0, 0, 0};

    for (int i = 1; i <= n; i++) {
        int buffer = i;
        while (buffer > 0) {
            for (int j = 0; j < 9; j++) {
                if (buffer >= reference[j].first) {
                    buffer -= reference[j].first;
                    for (int k = 0; k < 5; k++) {
                        roman[k] += (reference[j].second)[k];
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << roman[i] << " ";
    }
    return 0;
}





















