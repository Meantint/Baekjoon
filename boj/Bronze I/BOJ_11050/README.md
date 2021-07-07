# BOJ_11050 - 이항 계수 1

&nbsp;

- Baekjoon - [이항 계수 1](https://www.acmicpc.net/problem/11050)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 최댓값이 `10C5`이기 때문에 `int` 범위 안이므로 이항 계수를 실제로 구하는 과정처럼 구하면 된다.

- 먼저 나누면 버려지는 소수점이 생길 수 있으므로 먼저 곱해준다.

## Code

```cpp
#include <iostream>

using namespace std;

int n, k;
int answer = 1;

int main()
{
    cin >> n >> k;
    // 나누기 보다 먼저 곱해줘야 쓸데없는 소수점이 생기지 않는다.
    for (int i = 0; i < k; ++i) {
        answer *= (n - i);
    }
    for (int i = 0; i < k; ++i) {
        answer /= (i + 1);
    }
    cout << answer << '\n';

    return 0;
}
```
