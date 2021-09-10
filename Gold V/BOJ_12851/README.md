# BOJ_12851 - 숨바꼭질 2

&nbsp;

## 문제/코드 링크

- [BOJ_12851 - 숨바꼭질 2](https://www.acmicpc.net/problem/12851)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `isVisited`를 `vector<bool>` 타입으로 만드는 경우 반례가 생긴다.

  - `n`이 `1`인 경우 `1 * 2 = 2`, `1 + 1 = 2`로 `2`를 만드는 다른 방법이 두가지 있다. 그러므로 예외 처리해줘야 한다.

  - `isVisited`를 아예 없애버리는 경우 당연한 것이지만 메모리 초과 뜬다..

  - 해결 방법으로 `isVisited`를 `vector<int>` 타입으로 만들었다.

    - `isVisited[k]` : `k` 지점으로 올 수 있는 최소 이동 횟수

    - `dist + 1`이 `isVisited[k]` 이하여만 `queue`에 들어갈 수 있도록 코딩하였다.

## Code

```cpp
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
```
