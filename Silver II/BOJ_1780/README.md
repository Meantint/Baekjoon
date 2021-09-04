# BOJ_1780 - 종이의 개수

&nbsp;

## 문제/코드 링크

- [BOJ_1780 - 종이의 개수](https://www.acmicpc.net/problem/1780)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 분할정복을 이용해서 `isSame()`이 `true`인 경우 하나의 종이값으로 나타낼 수 있으므로 현재 종이의 번호 개수를 1개 늘려준 후 리턴한다.

- `isSame()`이 `false`인 경우 하나의 종이값으로 표현할 수 없기 때문에 `9`개로 분할하여 재귀적으로 함수를 반복한다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> answer(3, 0);
vector<vector<int>> board;

bool isSame(int y, int x, int len)
{
    int base = board[y][x];

    for (int r = 0; r < len; ++r) {
        for (int c = 0; c < len; ++c) {
            if (board[y + r][x + c] != base) {
                return false;
            }
        }
    }

    return true;
}

void DFS(int y, int x, int len)
{
    if (isSame(y, x, len)) {
        ++answer[board[y][x] + 1];

        return;
    }

    int newLen = len / 3;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            DFS(y + r * newLen, x + c * newLen, newLen);
        }
    }
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    DFS(0, 0, n);

    for (int i = 0; i < 3; ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}
```
