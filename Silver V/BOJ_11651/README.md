# BOJ_11651 - 좌표 정렬하기 2

&nbsp;

## 문제/코드 링크

- [BOJ_11651 - 좌표 정렬하기 2](https://www.acmicpc.net/problem/11651)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<pair<int, int>>` 타입 변수로 선언했기 때문에 일반 `sort`를 사용하면 `first`를 우선하는 오름차순 정렬이 된다.

- 그러므로 `second`를 우선하도록 `comp` 함수를 선언해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> info;

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main()
{
    cin >> n;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i].first >> info[i].second;
    }
    sort(info.begin(), info.end(), comp);

    for (int i = 0; i < n; ++i) {
        cout << info[i].first << ' ' << info[i].second << '\n';
    }

    return 0;
}
```
