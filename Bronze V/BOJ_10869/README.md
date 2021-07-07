# BOJ_10869 - 사칙연산

&nbsp;

- Baekjoon - [사칙연산](https://www.acmicpc.net/problem/10869)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 간단한 연산

## Code

```cpp
#include <iostream>

using namespace std;

int a, b;

int main()
{
    cin >> a >> b;

    cout << a + b << '\n'
         << a - b << '\n'
         << a * b << '\n'
         << a / b << '\n'
         << a % b << '\n';

    return 0;
}
```
