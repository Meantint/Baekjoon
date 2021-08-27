# BOJ_1330 - 두 수 비교하기

&nbsp;체감상 브론즈4 보다는 난이도가 낮아야 할 것 같다.

## 문제/코드 링크

- [BOJ_1330 - 두 수 비교하기](https://www.acmicpc.net/problem/1330)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `a`와 `b`를 입력받아 크기 비교를 하여 출력하면 된다.

## Code

```cpp
#include <iostream>

using namespace std;

int a, b;

int main()
{
    cin >> a >> b;

    if (a > b) {
        cout << '>' << '\n';
    }
    else if (a == b) {
        cout << "==" << '\n';
    }
    else {
        cout << '<' << '\n';
    }

    return 0;
}
```
