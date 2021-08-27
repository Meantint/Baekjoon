# BOJ_2439 - 별 찍기 - 2

&nbsp;공백부터 출력하는 것을 신경쓰면 된다.

## 문제/코드 링크

- [BOJ_2439 - 별 찍기 - 2](https://www.acmicpc.net/problem/2439)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 입력값 `n`에서 현재 행의 값을 빼준 만큼 공백을 먼저 넣어주면 된다.

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
