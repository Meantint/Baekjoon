# BOJ_1085 - 직사각형에서 탈출

&nbsp;동서남북 4군데 중 가장 가까운 위치를 찾는다.

## 문제/코드 링크

- [BOJ_1085 - 직사각형에서 탈출](https://www.acmicpc.net/problem/1085)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `(2 * x > w) ? (w - x) : x`: `x`가 `w`에 더 가깝다면 `w - x`를, `0`에 더 가깝다면 `x`를 반환한다.

- `(2 * y > h) ? (h - y) : y`: `y`가 `h`에 더 가깝다면 `h - y`를, `0`에 더 가깝다면 `y`를 반환한다.

- `min({w - x, x, h - y, y})`과 똑같다.

## Code

```cpp
#include <algorithm>
#include <iostream>

using namespace std;

int x, y, w, h;
int answer;

int main()
{
    cin >> x >> y >> w >> h;
    answer = min((2 * x > w) ? (w - x) : x, (2 * y > h) ? (h - y) : y);
    cout << answer << '\n';

    return 0;
}
```
