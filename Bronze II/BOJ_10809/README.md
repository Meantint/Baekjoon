# BOJ_10809 - 알파벳 찾기

&nbsp;

## 문제/코드 링크

- [BOJ_10809 - 알파벳 찾기](https://www.acmicpc.net/problem/10809)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 현재 탐색하는 문자가 방문한적이 없는 경우에만 `alpha[str[i] - 'a'] = i`를 실행해주면 된다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<int> alpha(26, -1);

int main()
{
    cin >> str;

    int size = str.size();
    for (int i = 0; i < size; ++i) {
        if (alpha[str[i] - 'a'] == -1) {
            alpha[str[i] - 'a'] = i;
        }
    }
    for (int i = 0; i < 26; ++i) {
        cout << alpha[i] << '\n';
    }

    return 0;
}
```
