# BOJ_1652 - 누울 자리를 찾아라

&nbsp;문제가 조금 헷갈렸다.

- Baekjoon - [누울 자리를 찾아라](https://www.acmicpc.net/problem/1652)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `board[i][j]`가 `.`인 경우

  - 가로인 경우 : `j`가 `0`이거나 `board[i][j - 1]`가 `X`인 경우에 `board[i][j + 1]`까지 `0`이라면 `col`값을 1증가 시켜준다.

  - 세로인 경우 : `i`가 `0`이거나 `board[i - 1][j]`가 `X`인 경우에 `board[i + 1][j]`까지 `0`이라면 `row`값을 1증가 시켜준다.

## Code

```cpp
#include <iostream>

using namespace std;

int n, row = 0, col;
char board[100][100];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '.') {
                if (i == 0 || (i - 1 >= 0 && board[i - 1][j] == 'X')) {
                    if (i + 1 < n && board[i + 1][j] == '.') {
                        ++row;
                    }
                }
                if (j == 0 || (j - 1 >= 0 && board[i][j - 1] == 'X')) {
                    if (j + 1 < n && board[i][j + 1] == '.') {
                        ++col;
                    }
                }
            }
        }
    }
    cout << col << ' ' << row << '\n';

    return 0;
}
```
