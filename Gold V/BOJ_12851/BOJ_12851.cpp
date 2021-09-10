#include <iostream>
#include <queue>
#include <vector>

#define INF 2112345678

using namespace std;

int n, k;

bool isSafe(int p)
{
    if (100001 <= p || p < 0) {
        return false;
    }
    return true;
}

pair<int, int> BFS()
{
    pair<int, int> ret = make_pair(-1, -1);

    vector<int> isVisited(100001, INF);
    queue<pair<int, int>> q;

    q.push(make_pair(n, 0));
    isVisited[n] = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur == k) {
            if (ret.first == -1) {
                ret.first = dist;
                ret.second = 1;
            }
            else if (ret.first == dist) {
                ++ret.second;
            }
            else {
                break;
            }
        }
        if (isSafe(cur - 1) && isVisited[cur - 1] >= dist + 1) {
            q.push(make_pair(cur - 1, dist + 1));
            isVisited[cur - 1] = dist + 1;
        }
        if (isSafe(cur + 1) && isVisited[cur + 1] >= dist + 1) {
            q.push(make_pair(cur + 1, dist + 1));
            isVisited[cur + 1] = dist + 1;
        }
        if (isSafe(cur * 2) && isVisited[cur * 2] >= dist + 1) {
            q.push(make_pair(cur * 2, dist + 1));
            isVisited[cur * 2] = dist + 1;
        }
    }

    return ret;
}

int main()
{
    cin >> n >> k;

    pair<int, int> answer = BFS();
    cout << answer.first << '\n'
         << answer.second << '\n';

    return 0;
}