# BOJ_17070 - 파이프 옮기기 1

&nbsp;`DP`를 이용하여 풀었다. 예전에 풀었던걸 보니 `BFS`로 풀었었더라.. 꽤 헷갈리는 문제이다. 카카오 블라인드 채용 문제인 [블록 이동하기](https://programmers.co.kr/learn/courses/30/lessons/60063)와 오브젝트를 지정하는 방식이 흡사한 것 같다.

- Baekjoon - [파이프 옮기기 1](https://www.acmicpc.net/problem/17070)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 파이프의 끝 부분에 벽이 있는지 없는지 혹은 `board`의 범위 내에 있는지를 확인 해주는 함수 `isCheck`를 만든다.

- 점화식(`i`와 `j`값 모두 `board`의 범위 내에 있다고 가정)

  - 가로 : `dp[i][j][0] = dp[i][j - 1][0] + dp[i - 1][j - 1][1]`

  - 대각선 : `dp[i][j][1] = dp[i][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j][2]`

  - 세로 : `dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j - 1][1]`

- `answer = dp[n - 1][n - 1][1]`인 이유 : (내가 푼 기준으로)좌표 `(n - 1, n - 1)`이 목표 지점이고 파이프의 끝 부분이 `(n - 1, n - 1)`을 가리키는 파이프 3개의 경우를 모두 받는 것이 `dp[n - 1][n - 1][1]`이기 때문이다. 대신에 `isCheck` 함수에서 끝 부분이 `board`의 범위를 벗어나므로 예외 케이스로 처리해줘야 한다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, answer = 0;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
vector<vector<int>> board;
// 가로, 세로의 위치 & 파이프 방향(0: 가로, 1: 대각선, 2: 세로)
vector<vector<vector<int>>> dp;

// 파이프의 끝 부분이 범위안에 들어오는지와 벽이 있는지 없는지 확인 해주는 함수
bool isCheck(int x, int y, int dir)
{
    if (x == n - 1 && y == n - 1) {
        return true;
    }
    if (x + dx[dir] >= n || y + dy[dir] >= n) {
        return false;
    }

    // 가로나 세로인 경우
    if (dir == 0 || dir == 2) {
        if (board[x + dx[dir]][y + dy[dir]] == 1) {
            return false;
        }
    }
    // 대각선인 경우
    else {
        for (int i = 0; i < 3; ++i) {
            if (board[x + dx[i]][y + dy[i]] == 1) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));  // 초기화
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(3, 0)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 파이프가 가로인 경우
            if (isCheck(i, j, 0)) {
                // 왼쪽의 범위에서 자유로울 때
                if (j - 1 >= 0) {
                    dp[i][j][0] += dp[i][j - 1][0];
                    // 위쪽의 범위도 자유롭다면 대각선에서도 가능
                    if (i - 1 >= 0) {
                        dp[i][j][0] += dp[i - 1][j - 1][1];
                    }
                }
            }
            // 파이프가 세로인 경우
            if (isCheck(i, j, 2)) {
                // 위쪽의 범위에서 자유로울 때
                if (i - 1 >= 0) {
                    dp[i][j][2] += dp[i - 1][j][2];
                    // 왼쪽의 범위도 자유롭다면 대각선에서도 가능
                    if (j - 1 >= 0) {
                        dp[i][j][2] += dp[i - 1][j - 1][1];
                    }
                }
            }
            // 파이프가 대각선인 경우
            if (isCheck(i, j, 1)) {
                // 왼쪽의 범위에서 자유로울 때
                if (j - 1 >= 0) {
                    dp[i][j][1] += dp[i][j - 1][0];
                }
                // 위쪽의 범위에서 자유로울 때
                if (i - 1 >= 0) {
                    dp[i][j][1] += dp[i - 1][j][2];
                }
                // 양쪽의 범위 모두 자유로울 때
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j][1] += dp[i - 1][j - 1][1];
                }
            }
        }
    }
    // for (int k = 0; k < 3; ++k) {
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             cout << dp[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    answer = dp[n - 1][n - 1][1];
    cout << answer << '\n';

    return 0;
}
```
