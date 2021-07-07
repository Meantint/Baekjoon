# BOJ_7573 - 고기잡이

&nbsp;왼쪽 상단의 좌표가 무조건 고기가 있는 점을 탐색했을 때 최대라고 생각했는데 다음과 같은 경우는 왼쪽 상단의 좌표가 고기가 있는 점이 아닐 때 가장 많은 고기를 잡을 수 있다.

## input.txt

```txt
4 12 4
1 2
1 3
2 1
3 1
```

## output.txt

```txt
4
```

왜 안되는지 스스로 알아보자..

- Baekjoon - [고기잡이](https://www.acmicpc.net/problem/7573)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 현재 가로 세로의 범위 안의 고기 개수를 반환하는 함수 `getCount` 함수를 선언했다.

- 가로와 세로의 길이를 `n`으로 지정해놓았고 고기의 좌표들이 모두 주어지므로 특정 `y`, `x` 좌표 라인에 고기가 있는지 없는지를 판단할 수 있다. 그렇기 때문에 고기가 있는 `y`, `x` 좌표를 모두 기록해놓기 위해 `existY`, `existX` 함수를 만들었다.

- `existY = 1`이고 `existX = 1`인 좌표는 모두 `getCount` 함수를 실행시키면서 `tmp`에 저장하고 `answer < tmp`라면 `answer`의 값을 `tmp`로 변경해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, l, m;
int answer = 0;
vector<pair<int, int>> save_pos;
vector<int> existY, existX;

int getCount(pair<int, int> pos, int lenY, int lenX)
{
    int ret = 0;

    for (int i = 0; i < m; ++i) {
        if (save_pos[i].first >= pos.first && save_pos[i].first <= pos.first + lenY) {
            if (save_pos[i].second >= pos.second && save_pos[i].second <= pos.second + lenX) {
                ++ret;
            }
        }
    }

    return ret;
}

void solve()
{
    int len = l / 2;

    for (int y = 0; y <= n; ++y) {
        if (existY[y] == 0) {
            continue;
        }
        for (int x = 0; x <= n; ++x) {
            if (existX[x] == 0) {
                continue;
            }

            for (int l = 1; l < len; ++l) {
                int tmp = getCount(make_pair(y, x), l, len - l);
                if (answer < tmp) {
                    answer = tmp;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> l >> m;
    existY = existX = vector<int>(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int y, x;
        cin >> y >> x;

        save_pos.push_back(make_pair(y, x));
        existY[y] = 1;
        existX[x] = 1;
    }

    solve();

    cout << answer << '\n';

    return 0;
}
```
