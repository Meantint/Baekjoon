# BOJ_2908 - 상수

&nbsp;

## 문제/코드 링크

- [BOJ_2908 - 상수](https://www.acmicpc.net/problem/2908)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `string` 타입의 대소 비교를 이용하여 풀었다.

- 숫자를 뒤집는 것은 `algorithm` 라이브러리의 `reverse`를 이용하였다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s1, s2;

int main()
{
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    cout << (s1 > s2 ? s1 : s2) << '\n';

    return 0;
}
```
