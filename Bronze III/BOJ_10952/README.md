# BOJ_10952 - A+B - 5

&nbsp;

- Baekjoon - [A+B - 5](https://www.acmicpc.net/problem/10952)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `a`와 `b` 모두 값이 `0`이라면 `break` 해준다.

- 위의 경우가 아닐때는 입력값들의 합을 출력해준다.

## Code

```cpp
#include <iostream>

using namespace std;

int n, a, b;

int main()
{
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        cout << a + b << '\n';
    }

    return 0;
}
```
