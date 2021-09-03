# BOJ_18111 - 마인크래프트

&nbsp;높이가 같은 경우 오름차순 정렬을 하고 있기 때문에 무조건 갱신해줘야하는데 조건 설정을 잘못했다...

## 문제/코드 링크

- [BOJ_18111 - 마인크래프트](https://www.acmicpc.net/problem/18111)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `0` ~ `256` 범위를 오름차순으로 전체 탐색한다.

  - 만약 전체 블록으로 모든 높이를 `k`로 만들 수 없다면 `break`를 실행한다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, m, b;
vector<vector<int>> board;

vector<int> AS()
{
    vector<int> ans = {2112345678, 0};

    int allBlock = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            allBlock += board[r][c];
        }
    }
    allBlock += b;

    for (int i = 0; i <= 256; ++i) {
        int ret = 0;

        if (allBlock < i * n * m) {  // 블록 개수가 모자라면
            break;
        }
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                int temp = i - board[r][c];
                if (temp >= 0) {  // 블록을 추가하는 경우
                    ret += temp;
                }
                else {
                    ret += temp * -2;
                }
            }
        }
        if (ans[0] >= ret) {
            ans[0] = ret;
            ans[1] = i;
        }
    }

    return ans;
}

int main()
{
    cin >> n >> m >> b;
    board = vector<vector<int>>(n, vector<int>(m));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> board[r][c];
        }
    }

    vector<int> answer = AS();
    cout << answer[0] << ' ' << answer[1] << '\n';

    return 0;
}
```
