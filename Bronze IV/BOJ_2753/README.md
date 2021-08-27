# BOJ_2753 - 윤년

&nbsp;

## 문제/코드 링크

- [BOJ_2753 - 윤년](https://www.acmicpc.net/problem/2753)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `400`부터 거꾸로 나눠주면 조금 더 간단한 것 같다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    if (n % 400 == 0) {
        cout << '1' << '\n';
    }
    else if (n % 100 == 0) {
        cout << '0' << '\n';
    }
    else if (n % 4 == 0) {
        cout << '1' << '\n';
    }
    else {
        cout << '0' << '\n';
    }

    return 0;
}
```
