# BOJ_1074 - Z

&nbsp;분할정복을 이용하였었는데 처음 구현한 것은 분할정복의 탈을 쓴 완전탐색 형태였다..

- Baekjoon - [Z](https://www.acmicpc.net/problem/1074)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `solve()`의 인자

  - `x` : 찾는 `row` 위치

  - `y` : 찾는 `col` 위치

  - `size` : 찾는 범위의 한 변 길이

- `Z` 모양의 순서대로 `1 ~ 4` 구역으로 나눴을 때

  - `1` 구역 : `x` & `y`의 값을 바꾸지 않고 `solve()`를 실행한다.

  - `2` 구역 : `y`의 값에 `size / 2`를 더해주고 `answer += half * half`를 해준 후 `solve()`를 실행한다.

  - `3` 구역 : `x`의 값에 `size / 2`를 더해주고 `answer += half * half * 2`를 해준 후 `solve()`를 실행한다.

  - `4` 구역 : `x`, `y` 둘 다 `size / 2`를 더해주고 `answer += half * half * 3`를 해준 후 `solve()`를 실행한다.

  - 공통으로 `solve()`를 실행할 때의 `size`를 현재 `size`에서 `2`로 나눈 값을 사용한다.

## Code

```cpp
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n, r, c, answer = 0;

void solve(int x, int y, int size)
{
    if (x == r && y == c) {
        return;
    }
    int half = size / 2;
    if (r < x + half) {
        if (c < y + half) {
            solve(x, y, half);
        }
        else {
            answer += half * half;
            solve(x, y + half, half);
        }
    }
    else {
        if (c < y + half) {
            answer += half * half * 2;
            solve(x + half, y, half);
        }
        else {
            answer += half * half * 3;
            solve(x + half, y + half, half);
        }
    }
}

int main()
{
    cin >> n >> r >> c;
    solve(0, 0, pow(2, n));
    cout << answer << '\n';

    return 0;
}
```
