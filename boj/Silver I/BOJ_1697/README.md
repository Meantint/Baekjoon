# BOJ_1697 - 숨바꼭질

&nbsp;`BFS`로 풀면 된다.

- Baekjoon - [숨바꼭질](https://www.acmicpc.net/problem/1697)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 현재의 이동한 시간과 수빈이의 포지션을 차례대로 담은 `queue<pair<int, int>>` 변수 `q`를 만든다.

- `q.empty()`가 `true`가 될 때 까지 while문을 반복한다.

- 방문한 적 있는지의 여부를 검사하는 `vector<bool>` 변수 `isVisited`를 선언한다.

- 현재 탐색중인`isVisited[cur]`가 `true`라면 더 볼 것 없이 `continue` 해준다.

- 만약 현재 위치 `cur`와 동생의 위치 `k`가 같다면 현재의 시간 `dist`를 `answer`에 저장하고 `break`로 while문을 강제 종료시킨다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, k, answer = -1;

int main()
{
    cin >> n >> k;

    vector<bool> isVisited(100010, false);
    queue<PII> q;
    q.push(make_pair(0, n));  // (이동 시간, 수빈이의 포지션)
    while (!q.empty()) {
        int dist = q.front().first;
        int cur = q.front().second;
        q.pop();

        // 이미 방문했다면
        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;

        // 현재 위치가 동생의 위치라면
        if (cur == k) {
            answer = dist;
            break;
        }
        // queue 삽입
        if (cur - 1 >= 0) {
            q.push(make_pair(dist + 1, cur - 1));
        }
        if (cur + 1 <= 100000) {
            q.push(make_pair(dist + 1, cur + 1));
        }
        if (cur * 2 <= 100000) {
            q.push(make_pair(dist + 1, cur * 2));
        }
    }
    cout << answer << '\n';

    return 0;
}
```
