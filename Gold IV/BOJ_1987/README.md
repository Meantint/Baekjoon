# BOJ_1987 - 알파벳

&nbsp;몇 번이고 다시 풀었다... `Bitmask`와 `DFS` 이용해서 풀었다.

## 문제/코드 링크

- [BOJ_1987 - 알파벳](https://www.acmicpc.net/problem/1987)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `DFS`의 경우 따로 배열을 저장하지 않고 값 변경 -> 함수 호출 -> 값 원상복귀의 패턴으로 사용가능하다. 그렇기 때문에 메모리 부분에서 장점이 있다.

- 이미 방문한 적이 있는 알파벳이라면 현재까지의 개수인 `cnt`가 `answer` 보다 크다면 갱신, 크지 않다면 그냥 함수를 종료해준다.

- 방문한 적 없는 알파벳이라면 현재까지의 알파벳 방문 정보인 `base`에 `board[y][x]`의 값을 넣어주고 상하좌우의 방향을 탐색하면서 배열 범위를 벗어나지 않는다면 재귀적으로 `dfs` 함수를 호출한다.

- `dfs` 함수가 종료됐을 때 `answer`에 담겨있는 정보가 정답이다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> board;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int answer = 0;
int base = 0;

bool isSafe(int y, int x)
{
    if (0 <= y && y < n && 0 <= x && x < m) {
        return true;
    }
    return false;
}

void dfs(int y, int x, int cnt)
{
    // cout << y << ", " << x << ", " << cnt << '\n';
    int pos = (1 << (board[y][x] - 'A'));
    if (base & pos) {  // 이미 방문한 적 있는 알파벳이라면
        --cnt;
        if (answer < cnt) {
            answer = cnt;
        }
        return;
    }

    base |= pos;

    for (int i = 0; i < 4; ++i) {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (isSafe(cy, cx)) {
            dfs(cy, cx, cnt + 1);
        }
    }

    base ^= pos;

    return;
}

int main()
{
    cin >> n >> m;
    board.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    dfs(0, 0, 1);

    cout << answer << '\n';

    return 0;
}
```
