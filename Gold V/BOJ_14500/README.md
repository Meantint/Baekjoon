# BOJ_14500 - 테트로미노

&nbsp;처음에 대칭 적용 안함. 다음으로 column의 범위를 `m`이 아닌 `n`으로 하는 실수 수정. 생각보다 구현이 다른 것들에 비해 약한가? 라는 생각이 들었다. 그리고 변수명을 예쁘게 적자고 하기에는 이 문제에 for문이 너무 많아서 어쩔수 없나? 싶기도 하다..

## 문제/코드 링크

- [BOJ_14500 - 테트로미노](https://www.acmicpc.net/problem/14500)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `rotate90()`

  - 시계 방향으로 90도 회전시키는 함수

- `reverse()`

  - 대칭 시켜주는 함수

- `isSafe(int r, int c, vector<vector<int>> rowInfo)`

  - 4개의 좌표 모두 배열 범위 안에 있는지의 여부를 판단해주는 함수

- `BF()`

  - 모든 범위를 탐색하면서 최댓값을 갱신해주는 함수

  - `Brute Force`

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int answer = 0;
vector<vector<int>> board;
vector<vector<vector<int>>> info = {
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
};

void rotate90()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            int temp = info[i][j][0];
            info[i][j][0] = info[i][j][1];
            info[i][j][1] = -temp;
        }
    }
}

void reverse()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            info[i][j][0] *= -1;
        }
    }
}

bool isSafe(int r, int c, vector<vector<int>> rowInfo)
{
    for (int i = 0; i < 4; ++i) {
        int cr = r + rowInfo[i][0];
        int cc = c + rowInfo[i][1];
        if (n <= cr || cr < 0 || m <= cc || cc < 0) {
            return false;
        }
    }

    return true;
}

void BF()
{
    // 일자형, 정사각형
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (c + 3 < m) {
                int temp = board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r][c + 3];
                if (answer < temp) {
                    answer = temp;
                }
            }
            if (r + 3 < n) {
                // cout << "r, c : " << r << ", " << c << '\n';
                int temp = board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 3][c];
                // cout << "temp : " << temp << '\n';
                if (answer < temp) {
                    answer = temp;
                }
            }
            if (r + 1 < n && c + 1 < m) {
                int temp = board[r][c] + board[r + 1][c] + board[r][c + 1] + board[r + 1][c + 1];
                if (answer < temp) {
                    answer = temp;
                }
            }
        }
    }

    // 모양이 4, 8개가 나오는 케이스
    for (int kk = 0; kk < 2; ++kk) {
        reverse();
        for (int k = 0; k < 4; ++k) {
            rotate90();
            // LeftTop ~ RightBottom
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < m; ++c) {
                    for (int i = 0; i < 3; ++i) {  // info 3가지의 경우
                        if (isSafe(r, c, info[i])) {
                            int temp = 0;
                            for (int j = 0; j < 4; ++j) {
                                temp += board[r + info[i][j][0]][c + info[i][j][1]];
                            }
                            if (answer < temp) {
                                answer = temp;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> board[r][c];
        }
    }

    BF();
    cout << answer << '\n';

    return 0;
}
```
