# BOJ_2884 - 알람 시계

&nbsp;

## 문제/코드 링크

- [BOJ_2884 - 알람 시계](https://www.acmicpc.net/problem/2884)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `h`와 `m` 값이 음수가 될 때 각각 `24`, `60`을 더해주면 된다.

- `m`이 음수가 되는 경우는 `h`를 `1` 감소시킨다.

## Code

```cpp
#include <iostream>

using namespace std;

int h, m;

int main()
{
    cin >> h >> m;

    m -= 45;
    if (m < 0) {
        m += 60;
        --h;
        if (h < 0) {
            h += 24;
        }
    }
    cout << h << ' ' << m << '\n';

    return 0;
}
```
