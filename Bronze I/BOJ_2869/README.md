# BOJ_2869 - 달팽이는 올라가고 싶다

&nbsp;

## 문제/코드 링크

- [BOJ_2869 - 달팽이는 올라가고 싶다](https://www.acmicpc.net/problem/2869)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 마지막 날은 밤에 내려가는 거리를 빼고 계산(생각할 필요가 없음)

  - 그러므로 전체 이동거리에서 낮에 올라가는 거리를 한 번 빼준다.

- 남은 거리를 `(a - b)`으로 나눠준다.

  - `(a - b)`으로 나눠떨어지지 않는 경우라도 그 거리만큼 올라가는데 낮 한 번을 소모해야하므로 `1`을 더해준다.

## Code

```cpp
#include <iostream>

using namespace std;

int a, b, v;
int ret;

int main()
{
    cin >> a >> b >> v;

    ret = 1;
    v -= a;                  // 마지막 날을 빼준다.
    ret += (v / (a - b));    // 낮과 밤을 합친 거리로 남은 거리를 나눠준다.
    if (v % (a - b) != 0) {  // 낮과 밤을 합친 거리로 딱 나눠떨어지지 않는다면 1을 더해줘야한다.
        ++ret;
    }

    cout << ret << '\n';

    return 0;
}
```
