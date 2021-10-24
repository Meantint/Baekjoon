# BOJ_13549 - 숨바꼭질 3

&nbsp;`priority_queue`를 이용해서 풀었다.

## 문제/코드 링크

- [BOJ_13549 - 숨바꼭질 3](https://www.acmicpc.net/problem/13549)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `cur * 2`의 경우 `cnt`에 들어가지 않기 때문에 `priority_queue`를 이용해 풀어야한다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;

    // first : 이동 횟수, second : 현재 위치
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<bool> isVisited(100001, false);
    pq.push(make_pair(0, n));
    while (!pq.empty()) {
        int cnt = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;

        if (cur == k) {
            cout << cnt << '\n';

            break;
        }

        if (cur - 1 >= 0) {
            pq.push(make_pair(cnt + 1, cur - 1));
        }
        if (cur + 1 <= 100000) {
            pq.push(make_pair(cnt + 1, cur + 1));
        }
        if (cur * 2 <= 100000) {
            pq.push(make_pair(cnt, cur * 2));
        }
    }

    return 0;
}
```
