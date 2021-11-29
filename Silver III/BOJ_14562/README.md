# BOJ_14562 - 태권왕

&nbsp;`BFS`를 이용해 풀었다.

## 문제/코드 링크

- [BOJ_14562 - 태권왕](https://www.acmicpc.net/problem/14562)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 초기값에서 증가할 수 있는 방향(1번, 2번 방법)을 Queue에 넣어주면서 가장 빨리 `start == target`인 경우를 찾고 찾았다면 현재의 `count` 값을 반환해준다.

- 시간 초과가 날 수 있기 때문에 `start > target`인 경우는 더 탐색하지 않고 `continue` 처리해준다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

int BFS(int s, int t)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(s, t), 0));

    while (!q.empty()) {
        int start = q.front().first.first;
        int target = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if (start == target) {
            return count;
        }
        if (start > target) {
            continue;
        }

        q.push(make_pair(make_pair(start * 2, target + 3), count + 1));
        q.push(make_pair(make_pair(start + 1, target), count + 1));
    }

    return -1;
}

int main()
{
    cin >> n;
    while (n--) {
        int s, t;
        cin >> s >> t;

        cout << BFS(s, t) << '\n';
    }

    return 0;
}
```
