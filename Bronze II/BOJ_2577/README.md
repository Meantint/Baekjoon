# BOJ_2577 - 숫자의 개수

&nbsp;

## 문제/코드 링크

- [BOJ_2577 - 숫자의 개수](https://www.acmicpc.net/problem/2577)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 곱하기 연산 후 각 자릿수의 값을 `numCount`에 넣어준다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int a, b, c;
vector<int> numCount(10, 0);

int main()
{
    cin >> a >> b >> c;

    int ret = a * b * c;
    while (ret != 0) {
        ++numCount[ret % 10];
        ret /= 10;
    }

    for (int i = 0; i < 10; ++i) {
        cout << numCount[i] << '\n';
    }

    return 0;
}
```
