// isVisited를 bool이 아닌 time 값으로 넣어서 풀었다.

#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int n, k;
int answerTime = INF;
int answerCnt = 0;

int main()
{
    cin >> n >> k;

    vector<int> isVisited(100001, INF);
    queue<PII> q;
    q.push(make_pair(0, n));
    isVisited[n] = 0;

    while (!q.empty()) {
        int time = q.front().first;
        int pos = q.front().second;
        q.pop();

        if (answerTime < time) break;
        if (pos == k) {
            answerTime = time;
            ++answerCnt;

            continue;
        }

        if (pos - 1 >= 0 && time <= isVisited[pos - 1]) {
            isVisited[pos - 1] = time;
            q.push(make_pair(time + 1, pos - 1));
        }
        if (pos + 1 <= 100000 && time <= isVisited[pos + 1]) {
            isVisited[pos + 1] = time;
            q.push(make_pair(time + 1, pos + 1));
        }
        if (pos * 2 <= 100000 && time <= isVisited[pos * 2]) {
            isVisited[pos * 2] = time;
            q.push(make_pair(time + 1, pos * 2));
        }
    }
    cout << answerTime << '\n'
         << answerCnt << '\n';

    return 0;
}