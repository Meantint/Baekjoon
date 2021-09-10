# BOJ_11404 - 플로이드

&nbsp;`Floyd` 사용 문제. 갈 수 없는 경로는 `0` 처리를 마지막에 해줘야한다.

## 문제/코드 링크

- [BOJ_11404 - 플로이드](https://www.acmicpc.net/problem/11404)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 똑같은 경로가 있다. 버스 요금만 다르기 때문에 이들 중 최솟값을 저장해둬야한다.

- 나머지는 일반적인 `Floyd` 알고리즘 작성하면 된다.

- 마지막에만 불가능 경로 `0`으로 처리

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int n, m;
vector<vector<int>> floyd;

int main()
{
    cin >> n >> m;
    floyd.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        int v1, v2, dist;
        cin >> v1 >> v2 >> dist;

        floyd[v1][v2] = min(floyd[v1][v2], dist);
        // floyd[v2][v1] = dist;
    }

    for (int i = 1; i <= n; ++i) {
        floyd[i][i] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (floyd[i][j] == INF) {
                cout << 0 << ' ';
            }
            else {
                cout << floyd[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}
```
