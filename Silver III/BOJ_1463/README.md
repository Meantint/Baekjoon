# BOJ_1463 - 1로 만들기

&nbsp;`BFS`로 풀었다.

## 문제/코드 링크

- [BOJ_1463 - 1로 만들기](https://www.acmicpc.net/problem/1463)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `(Current, Count)`를 저장하는 `queue<PII>` 변수 `q`를 만든다.

- `cur`가 이미 방문했는지를 체크하는 `vector<bool>` 변수 `isVisited`를 만든다.

- while문 조건 : `q.empty()`가 `true`일 때까지

  - 이미 방문한적이 있다면 `continue` 해준다.

  - `cur`가 `1`이라면 `answer = cnt`를 해주고 `break` 해준다.

  - `cur % 3`이 `0`이라면 `q.push()` 해준다.

  - `cur % 2`가 `0`이라면 `q.push()` 해준다.

  - `cur - 1`을 `q.push()` 해준다.

## Code

```cpp
#include <iostream>
#include <queue>

#define PII pair<int, int>

using namespace std;

int x, answer = -1;
queue<PII> q;

int main()
{
    cin >> x;

    vector<bool> isVisited(x + 1, false);
    q.push(make_pair(x, 0));
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 이미 방문한적이 있다면
        if (isVisited[cur]) {
            continue;
        }
        isVisited[cur] = true;

        if (cur == 1) {
            answer = cnt;
            break;
        }
        if (cur % 3 == 0) {
            q.push(make_pair(cur / 3, cnt + 1));
        }
        if (cur % 2 == 0) {
            q.push(make_pair(cur / 2, cnt + 1));
        }
        q.push(make_pair(cur - 1, cnt + 1));
    }
    cout << answer << '\n';

    return 0;
}
```
