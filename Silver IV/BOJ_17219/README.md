# BOJ_17219 - 비밀번호 찾기

&nbsp;간단한 `map`에 대한 사용법만 알면 된다.

## 문제/코드 링크

- [BOJ_17219 - 비밀번호 찾기](https://www.acmicpc.net/problem/17219)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `map`에 대해서 공부하고 풀어보자.

## Code

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;
string s1, s2;
map<string, string> info;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        info[s1] = s2;
    }
    for (int i = 0; i < m; ++i) {
        cin >> s1;
        cout << info[s1] << '\n';
    }

    return 0;
}
```
