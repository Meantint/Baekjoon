#include <bits/stdc++.h>

using namespace std;

int main()
{
        int L, P;
        int people[5];

        cin >> L >> P;
        int num = L * P;
        for (int i = 0; i < 5; ++i) {
                cin >> people[i];
                people[i] -= num;
        }

        for (int i = 0; i < 5; ++i) {
                cout << people[i] << ' ';
        }

        return 0;
}