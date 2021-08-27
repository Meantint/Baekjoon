# BOJ_2739 - 구구단

&nbsp;

## 문제/코드 링크

- [BOJ_2739 - 구구단](https://www.acmicpc.net/problem/2739)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `n`을 입력받아서 구구단 형식으로 출력해준다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    for (int i = 1; i < 10; ++i) {
        cout << n << " * " << i << " = " << n * i << '\n';
    }

    return 0;
}
```
