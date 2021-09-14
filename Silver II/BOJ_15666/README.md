# BOJ_15666 - N과 M (12)

&nbsp;

## 문제/코드 링크

- [BOJ_15666 - N과 M (12)](https://www.acmicpc.net/problem/15666)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 중복되는 원소를 제거해준다.

  - `info.erase(unique(info.begin(), info.end()), info.end())`로 실행해준다.

    - 실행하기전 `info`는 꼭 정렬되어 있어야 한다.

- 중복 원소 제거 후 `DFS`를 통해 `curInfo`가 원하는 사이즈 `m` 만큼 채워졌을 때 출력을 해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int iSize;
vector<int> info;

void DFS(int idx, vector<int> curInfo)
{
    curInfo.push_back(info[idx]);
    if (curInfo.size() == m) {
        for (int i = 0; i < m; ++i) {
            cout << curInfo[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = idx; i < iSize; ++i) {
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
    info.erase(unique(info.begin(), info.end()), info.end());

    iSize = info.size();
    for (int i = 0; i < iSize; ++i) {
        DFS(i, {});
    }

    return 0;
}
```
