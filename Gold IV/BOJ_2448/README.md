# BOJ_2448 - 별 찍기 - 11

&nbsp;

## 문제/코드 링크

- [BOJ_2448 - 별 찍기 - 11](https://www.acmicpc.net/problem/2448)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 분할 정복을 이용해서 풀었다.

- 기준점만 잘 잡으면 어렵지 않은 것 같다.

  - 내가 잡은 기준점은 삼각형의 가장 꼭대기 점이다.

- `DC(int r, int c, int size)`

  - `r` : 현재 꼭대기 점의 row 위치

  - `c` : 현재 꼭대기 점의 column 위치

  - `size` : 현재 나타내야하는 사이즈

  - 최소 단위를 `size`가 `3`인 경우로 생각할 수 있고 `size`가 `3`인 경우 별을 놓아야 하는 배열의 위치에 넣어주었다.

## Code

```cpp
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> board;

void DC(int r, int c, int size)
{
    if (size == 3) {
        board[r][c] = '*';
        board[r + 1][c - 1] = board[r + 1][c + 1] = '*';
        for (int i = 0; i < 5; ++i) {
            board[r + 2][c + i - 2] = '*';
        }

        return;
    }

    int newSize = size / 2;
    DC(r, c, newSize);
    DC(r + newSize, c - newSize, newSize);
    DC(r + newSize, c + newSize, newSize);
}

int main()
{
    cin >> n;
    board = vector<vector<char>>(n, vector<char>(n * 2 - 1, ' '));

    DC(0, (n * 2 - 1) / 2, n);

    int rSize = board.size();
    int cSize = board[0].size();
    for (int r = 0; r < rSize; ++r) {
        for (int c = 0; c < cSize; ++c) {
            cout << board[r][c];
        }
        cout << '\n';
    }

    return 0;
}
```
