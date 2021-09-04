# BOJ_1992 - 쿼드트리

&nbsp;

## 문제/코드 링크

- [BOJ_1992 - 쿼드트리](https://www.acmicpc.net/problem/1992)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 분할정복을 이용해서 `isSame()`이 `true`인 경우 하나의 종이값으로 나타낼 수 있으므로 현재 종이의 번호를 `answer`에 추가해주고 리턴한다.

- `isSame()`이 `false`인 경우 하나의 종이값으로 표현할 수 없기 때문에 `4`개로 분할하여 재귀적으로 함수를 반복한다.

  - 분할하기 전 `answer`에 `(`를 추가하고 `4`번의 분할과정이 끝났다면 `)`를 `answer`에 추가해준다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string answer = "";
vector<vector<char>> board;

bool isSame(int y, int x, int len)
{
    char base = board[y][x];
    for (int r = 0; r < len; ++r) {
        for (int c = 0; c < len; ++c) {
            if (base != board[y + r][x + c]) {
                return false;
            }
        }
    }

    return true;
}

void DFS(int y, int x, int len)
{
    if (isSame(y, x, len)) {
        answer += board[y][x];
    }
    else {
        answer += '(';

        int newLen = len / 2;
        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < 2; ++c) {
                DFS(y + r * newLen, x + c * newLen, newLen);
            }
        }

        answer += ')';
    }
}

int main()
{
    cin >> n;
    board = vector<vector<char>>(n, vector<char>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    DFS(0, 0, n);

    cout << answer << '\n';

    return 0;
}
```
