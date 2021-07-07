#include <bits/stdc++.h>

using namespace std;

int num;

int main()
{
    cin >> num;
    num = 1000 - num;

    int answer = 0;
    int cost[6] = { 500, 100, 50, 10, 5, 1 };
    for (int i = 0; i < 6; ++i) {
        if (num == 0) {
            break;
        }
        answer += num / cost[i];
        num %= cost[i];
    }

    cout << answer << '\n';

    return 0;
}