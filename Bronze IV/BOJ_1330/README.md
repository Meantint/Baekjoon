# BOJ_1330 - 두 수 비교하기

&nbsp;개인적으로 왜 브론즈5 레벨이 아닌지 잘 모르겠는 문제.

- Baekjoon - [두 수 비교하기](https://www.acmicpc.net/problem/1330)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

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
