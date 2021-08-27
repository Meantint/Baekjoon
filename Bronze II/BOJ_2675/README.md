# BOJ_2675 - 문자열 반복

&nbsp;

## 문제/코드 링크

- [BOJ_2675 - 문자열 반복](https://www.acmicpc.net/problem/2675)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 문제에 나와있는 그대로 구현하면 된다.

## Code

```cpp
#include <iostream>
#include <string>

using namespace std;

int n, t;
string str;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> str;
        for (auto& s : str) {
            for (int i = 0; i < n; ++i) {
                cout << s;
            }
        }
        cout << '\n';
    }

    return 0;
}
```
