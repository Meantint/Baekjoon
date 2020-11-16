# BOJ_2439 - 별 찍기 - 2

&nbsp;기본적인 별 찍기 문제이다..?

- Baekjoon - [별 찍기 - 2](https://www.acmicpc.net/problem/2439)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 이중 for문으로 쉽게 해결할 수 있다..?

## Code

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j != i; --j) {
            cout << ' ';
        }
        for (int j = i; j >= 0; --j) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
```
