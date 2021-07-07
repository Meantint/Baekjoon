#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define DF 1000000

using namespace std;

int n, answer;
int minCnt = DF;
vector<int> money = {7, 5, 2, 1};
vector<bool> isCheck;

int main()
{
    cin >> n;
    isCheck.resize(n + 1, false);

    queue<PII> q;
    for (int i = 0; i < 4; ++i) {
        q.push(make_pair(1, money[i]));
    }
    while (!q.empty()) {
        int cnt = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (cost > n) continue;
        if (isCheck[cost]) continue;
        if (cost == n) {
            answer = cnt;
            break;
        }
        for (int i = 0; i < 4; ++i) {
            q.push(make_pair(cnt + 1, cost + money[i]));
        }
        isCheck[cost] = true;
    }
    cout << answer << '\n';

    return 0;
}