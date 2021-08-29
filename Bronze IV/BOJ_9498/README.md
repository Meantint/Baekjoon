# BOJ_9498 - 시험 성적

&nbsp;

## 문제/코드 링크

- [BOJ_9498 - 시험 성적](https://www.acmicpc.net/problem/9498)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 문제에서 요구한대로 구현하면 된다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;

    if (90 <= n && n <= 100) {
        cout << 'A' << '\n';
    }
    else if (80 <= n && n <= 89) {
        cout << 'B' << '\n';
    }
    else if (70 <= n && n <= 79) {
        cout << 'C' << '\n';
    }
    else if (60 <= n && n <= 69) {
        cout << 'D' << '\n';
    }
    else {
        cout << 'F' << '\n';
    }

    return 0;
}
```
