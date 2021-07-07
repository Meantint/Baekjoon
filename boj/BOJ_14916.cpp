#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> dp(n + 1, -1);
    vector<bool> isVisited(n + 1, false);
    queue<PII> q;
    q.push(make_pair(1, 2));
    q.push(make_pair(1, 5));

    while (!q.empty()) {
        int dist = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (cur > n) continue;
        if (isVisited[cur]) continue;
        isVisited[cur] = true;
        dp[cur] = dist;
        if (cur == n) break;
        q.push(make_pair(dist + 1, cur + 5));
        q.push(make_pair(dist + 1, cur + 2));
    }

    cout << dp[n] << '\n';

    return 0;
}