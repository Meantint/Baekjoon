#include <bits/stdc++.h>

using namespace std;

int main()
{
        long long n;
        cin >> n;

        vector<long long> dice;
        for (int i = 0; i < 6; ++i) {
                long long num;
                cin >> num;

                dice.push_back(num);
        }

        if (n == 1) {
                cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4] + dice[5] -
                            max({dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]})
                     << '\n';
                return 0;
        }
        long long side_3 = 4;
        long long dice_3 = min(dice[0], dice[5]) + min(dice[1], dice[4]) + min(dice[2], dice[3]);
        long long side_2 = 8 * n - 12;
        long long dice_2 = 1000;
        for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                        if (i == j)
                                continue;
                        if (i + j == 5)
                                continue;
                        dice_2 = min(dice_2, dice[i] + dice[j]);
                }
        }
        long long side_1 = 5 * n * n - 16 * n + 12;
        long long dice_1 = min({dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]});

        long long answer = side_3 * dice_3 + side_2 * dice_2 + side_1 * dice_1;
        cout << answer << '\n';

        return 0;
}