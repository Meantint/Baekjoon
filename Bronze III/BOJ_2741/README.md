# BOJ_2741 - N 찍기

&nbsp;

## 문제/코드 링크

- [BOJ_2741 - N 찍기](https://www.acmicpc.net/problem/2741)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 1부터 입력값까지 출력해주면 된다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << i << '\n';
    }

    return 0;
}
```
