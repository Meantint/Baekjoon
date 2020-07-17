---
title: "BOJ_1043 거짓말"
date: 2020-07-17T16:05:00+09:00
categories: [
	"BOJ",
]
tags: [
	"BOJ",
	"Baekjoon",
	"BOJ_1043",
]
cover: ""
draft: false
---

[[BOJ_1043](https://www.acmicpc.net/problem/1043) - [거짓말](https://www.acmicpc.net/problem/1043)]

2차원 배열을 만들어서 진실을 아는 사람과 파티로 연결된 사람들을 모두 제거하는 방식으로 문제를 풀었는데, 다른 사람들의 대부분은 `Union_Find`를 이용하여 풀었더라. `Union_Find`를 공부하자.

# 풀이

<center>

|        | 사람 -> |   1 |   2 |   3 |   4 |
| :----: | ------: | --: | --: | --: | --: |
| 파티 ↓ |         |     |     |     |     |
|   1    |         |   1 |   1 |   0 |   0 |
|   2    |         |   0 |   0 |   1 |   0 |
|   3    |         |   0 |   1 |   1 |   1 |

</center>
<figcaption>파티, 사람간의 관계를 갖는 2차원 배열</figcaption>

- 만약 진실을 알고 있는 사람이 있다면, 그 사람이 들어간 파티 번호를 찾은 후, 2차원 배열에서 가로 세로로 이어진 모든 연결(value가 1인 값들의 연결)을 제거한다.

  - 연결을 제거하는 위치에서 재귀적으로 반복한다.(진실을 알고 있는 사람과 이어져있는 다른 사람의 파티가 존재하는지)

- 그 후 파티를 검색하면서 1이 존재하는 파티(거짓을 말해도 상관없는 파티)를 발견하면 `++answer`를 해준 후 `break`한다.

- n번 사람이 진실을 알고 있다고 할 때

  1.  n번이 속해있는 파티에서는 무조건 진실을 말해야 한다.

      - `vec[1][n]` ~ `vec[m][n]` 중 value가 1인 곳(n번 사람이 파티에 속한 곳)을 찾는다.

  2.  찾은 파티에서 순차적으로 탐색(1번 사람부터 N번 사람까지)하면서 `value = 1`인 곳이 있으면

      1.  `value = 0`으로 바꾼다.

      2.  `value = 0`으로 바꾼 위치에서 `1번`을 재귀적으로 실행한다.

# Code

```C++
#include <bits/stdc++.h>

using namespace std;

void erase(vector<vector<int>>& vec, int x, int y)
{
        vec[x][y] = 0;
        for (int i = 1; i < vec.size(); ++i) {
                if (vec[i][y] == 1) {
                        erase(vec, i, y);
                }
        }
        for (int j = 1; j < vec[0].size(); ++j) {
                if (vec[x][j] == 1) {
                        erase(vec, x, j);
                }
        }
}

int main()
{
        int answer = 0;

        int n, m;
        cin >> n >> m;

        vector<vector<int>> vec(m + 1, vector<int>(n + 1, 0));
        vector<int> truth(n + 1, 0);

        int num;
        cin >> num;
        for (int i = 0; i < num; ++i) {
                int tmp;
                cin >> tmp;

                truth[tmp] = 1;
        }
        for (int i = 0; i < m; ++i) {
                int T;
                cin >> T;
                for (int j = 0; j < T; ++j) {
                        int tmp;
                        cin >> tmp;
                        vec[i + 1][tmp] = 1;
                }
        }

        int size = truth.size();
        for (int i = 1; i < size; ++i) {
                if (truth[i] == 1) {
                        for (int j = 1; j < m + 1; ++j) {
                                if (vec[j][i] == 1) {
                                        erase(vec, j, i);
                                }
                        }
                }
        }
        int row = vec.size();
        int col = vec[0].size();
        for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                        if (vec[i][j] == 1) {
                                ++answer;
                                break;
                        }
                }
        }
        cout << answer << '\n';

        return 0;
}
```
