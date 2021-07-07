# BOJ_17135 - 캐슬 디펜스

&nbsp;`dfs`와 구현을 이용해서 풀었다. 요즘 문제푸는 시간이 훨씬 길어졌는데 내면 한 번에 통과하는 것 같다. 뭐가 더 좋은걸까...? 흠..

- 1Baekjoon - [캐슬 디펜스](https://www.acmicpc.net/problem/17135)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 초기 형태를 받는 `vector<vector<int>>`형 변수 `board`를 선언한다.

- `arr.size() == 3`인 경우 궁수 3명이 모두 배치된 것이기 떄문에 `simul` 함수를 실행시킨다.

- 나머지는 모두 구현

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, m, d;
int answer = -1;
vector<vector<int>> board;

int Abs(int n1, int n2)
{
    int res = n1 - n2;
    return (res < 0) ? res * -1 : res;
}

bool isEmpty(vector<vector<int>> v)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

void simul(vector<int> arr)
{
    vector<vector<int>> copy_board = board;

    int cnt = 0;
    while (!isEmpty(copy_board)) {
        vector<PII> current_pos(3, make_pair(-1, -1));
        vector<int> min_dist(3, 2112345678);
        int current_idx = -1;

        for (int i = 0; i < 3; ++i) {
            ++current_idx;
            for (int c = 0; c < m; ++c) {
                for (int r = n - 1; r >= 0; --r) {
                    if (copy_board[r][c] == 1) {
                        if (min_dist[current_idx] > Abs(n, r) + Abs(arr[i], c) && d >= Abs(n, r) + Abs(arr[i], c)) {
                            current_pos[current_idx] = make_pair(r, c);
                            min_dist[current_idx] = Abs(n, r) + Abs(arr[i], c);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (min_dist[i] != 2112345678 && copy_board[current_pos[i].first][current_pos[i].second] == 1) {
                copy_board[current_pos[i].first][current_pos[i].second] = 0;
                ++cnt;
            }
        }
        for (int c = 0; c < m; ++c) {
            copy_board[n - 1][c] = 0;
            for (int r = n - 2; r >= 0; --r) {
                if (copy_board[r][c] == 1) {
                    copy_board[r + 1][c] = 1;
                    copy_board[r][c] = 0;
                }
            }
        }
    }
    if (answer < cnt) {
        answer = cnt;
    }
    return;
}

void dfs(vector<int> arr, int pos)
{
    if (arr.size() == 3) {
        simul(arr);

        return;
    }

    for (int i = pos + 1; i < m; ++i) {
        arr.push_back(i);
        dfs(arr, i);
        arr.pop_back();
    }
}

void solve()
{
    vector<int> arr;
    for (int i = 0; i < m; ++i) {
        arr.push_back(i);
        dfs(arr, i);
        arr.pop_back();
    }

    return;
}

int main()
{
    cin >> n >> m >> d;

    board = vector<vector<int>>(n + 1, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    solve();

    cout << answer << '\n';

    return 0;
}
```
