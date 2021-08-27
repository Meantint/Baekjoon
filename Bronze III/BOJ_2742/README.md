# BOJ_2742 - 기찍 N

&nbsp;

## 문제/코드 링크

- [BOJ_2742 - 기찍 N](https://www.acmicpc.net/problem/2742)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 1부터 입력값까지 역순으로 출력해주면 된다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    for (int i = n; i >= 1; --i) {
        cout << i << '\n';
    }

    return 0;
}
```
