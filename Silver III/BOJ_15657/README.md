# BOJ_15657 - N과 M (8)

&nbsp;

## 문제/코드 링크

- [BOJ_15657 - N과 M (8)](https://www.acmicpc.net/problem/15657)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `DFS`를 이용하여서 조합을 구현하였다.

- `curInfo`에 원소를 넣은 후 사이즈가 `m`과 같다면 출력해준 후 `return`한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> info;

void DFS(int idx, vector<int> curInfo)
{
    if (idx == n) {
        return;
    }
    curInfo.push_back(info[idx]);
    if (curInfo.size() == m) {
        for (int i = 0; i < m; ++i) {
            cout << curInfo[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < n; ++i) {
        DFS(i, curInfo);
    }
}

int main()
{
    cin >> n >> m;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    sort(info.begin(), info.end());
    for (int i = 0; i < n; ++i) {
        DFS(i, {});
    }

    return 0;
}
```
