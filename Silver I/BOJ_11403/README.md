# BOJ_11403

&nbsp;

## 문제/코드 링크

- [BOJ_11403](https://www.acmicpc.net/problem/11403)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `BFS` 함수를 만들고 `start`에서 출발하여 갈 수 있는 노드들은 `answer[start][k] = 1` 처리해준다.

- 각 배열 행에 대한 `BFS` 함수를 실행시켜주면 된다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> answer;

void BFS(int start)
{
    vector<bool> isVisited(n, false);
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (board[start][i] != 0) {
            // cout << "start " << start << " push " << i << '\n';
            q.push(i);
            isVisited[i] = true;
            answer[start][i] = 1;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; ++i) {
            int next = board[cur][i];

            if (next != 0 && !isVisited[i]) {
                // cout << "start " << start << " push " << i << '\n';
                q.push(i);
                isVisited[i] = true;
                answer[start][i] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    answer = vector<vector<int>>(n, vector<int>(n, 0));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> board[r][c];
        }
    }

    for (int r = 0; r < n; ++r) {
        BFS(r);
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << answer[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}
```
