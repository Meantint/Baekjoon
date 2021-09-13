# BOJ_15650 - N과 M (2)

&nbsp;`next_permutation`을 이용해 풀었다.

## 문제/코드 링크

- [BOJ_15650 - N과 M (2)](https://www.acmicpc.net/problem/15650)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 골라야 하는 개수 `m` 만큼 `v`에 `0`을 넣어준다.

- `do-while`문을 돌면서 `vector<int>` 변수 `tmp`를 만들고 `v[i]`가 `0`이라면 `tmp.push_back(num[i])` 해준다.

- 모두 `tmp`에 넣은 후 `answer.push_back(tmp)`를 해준다.

- `next_permutation(v.begin(), v.end())`를 이용해 다음 순열로 접근한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> answer;

int main()
{
    cin >> n >> m;

    vector<int> v(n, 1);
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        num[i] = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        v[i] = 0;
    }
    sort(v.begin(), v.end());
    do {
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            if (v[i] == 0) {
                tmp.push_back(num[i]);
            }
        }
        answer.push_back(tmp);
    } while (next_permutation(v.begin(), v.end()));
    for (auto& ans : answer) {
        for (auto& elem : ans) {
            cout << elem << ' ';
        }
        cout << '\n';
    }

    return 0;
}
```
