# BOJ_2438 - 별 찍기 - 1

&nbsp;기본적인 별 찍기 문제이다.

- Baekjoon - [별 찍기 - 1](https://www.acmicpc.net/problem/2438)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 이중 for문으로 쉽게 해결할 수 있다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
```
