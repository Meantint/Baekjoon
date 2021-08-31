# BOJ_1181 - 단어 정렬

&nbsp;`sort` 친구 `comp`를 설정해주자.

## 문제/코드 링크

- [BOJ_1181 - 단어 정렬](https://www.acmicpc.net/problem/1181)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 길이 순으로 오름차순하고, 길이가 같다면 사전순으로 정렬해주는 함수 `comp`를 만든다.

- `sort(str.begin(), str.end(), comp)` 해준다.

- `str.erase(unique(str.begin(), str.end()), str.end())`를 통해 중복된 값을 제거해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> str;

bool comp(const string &s1, const string &s2)
{
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

int main()
{
    cin >> n;
    str.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    sort(str.begin(), str.end(), comp);
    str.erase(unique(str.begin(), str.end()), str.end());

    for (auto &s : str) {
        cout << s << '\n';
    }

    return 0;
}
```
