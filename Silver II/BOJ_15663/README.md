# BOJ_15663 - N과 M (9)

&nbsp;[N과 M (8)](https://www.acmicpc.net/problem/15657)과 유사한 문제. 오름차순이 아닐 수 있다는 것에서 차이가 있다.

## 문제/코드 링크

- [BOJ_15663 - N과 M (9)](https://www.acmicpc.net/problem/15663)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 가능한 모든 경우의 조합들을 `answer`에 넣어준다.

- `row` 기준으로 오름차순 정렬해준 후 중복되는 원소가 있으면 제거한다.

  - `answer.erase(unique(answer.begin(), answer.end()), answer.end())`이 중복제거 코드

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> info, comb;
vector<vector<int>> answer;

void DFS(int idx, vector<int> curInfo)
{
    curInfo.push_back(idx);
    if (curInfo.size() == m) {
        answer.push_back(curInfo);
        return;
    }

    int cSize = curInfo.size();
    for (int i = 0; i < n; ++i) {
        bool putThis = true;
        for (int j = 0; j < cSize; ++j) {
            if (i == curInfo[j]) {
                putThis = false;
                break;
            }
        }
        if (putThis) {
            DFS(i, curInfo);
        }
    }

    return;
}

int main()
{
    cin >> n >> m;
    info.resize(n);
    comb.resize(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }
    sort(info.begin(), info.end());
    for (int i = 0; i < m; ++i) {
        comb[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        DFS(i, {});
    }
    int aSize = answer.size();
    for (int i = 0; i < aSize; ++i) {
        for (int j = 0; j < m; ++j) {
            answer[i][j] = info[answer[i][j]];
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    aSize = answer.size();
    for (int i = 0; i < aSize; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
```
