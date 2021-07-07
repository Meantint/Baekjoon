#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int h, y;

int main()
{
    cin >> h >> y;
    vector<int> dp(y + 1, 0);

    queue<PII> q;
    q.push(make_pair(0, h));
    while (!q.empty()) {
        int year = q.front().first;
        int price = q.front().second;
        // cout << year << ", " << price << '\n';
        q.pop();

        if (year > y) continue;
        // if (dp[year] != 0) continue;
        // dp[year] = price;
        dp[year] = max(dp[year], price);
        q.push(make_pair(year + 5, dp[year] * 135 / 100));
        q.push(make_pair(year + 3, dp[year] * 120 / 100));
        q.push(make_pair(year + 1, dp[year] * 105 / 100));
    }
    cout << dp[y] << '\n';

    return 0;
}