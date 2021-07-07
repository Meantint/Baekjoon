# BOJ_10950 - A+B - 3

&nbsp;

- Baekjoon - [A+B - 3](https://www.acmicpc.net/problem/10950)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `n` 값 만큼 반복 출력해주면 된다.

## Code

```cpp
#include <iostream>

using namespace std;

int n, a, b;

int main()
{
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}
```
