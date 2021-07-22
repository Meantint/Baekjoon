# BOJ_1946 - 신입 사원

&nbsp;그리디 문제입니다.

- Baekjoon - [신입 사원](https://www.acmicpc.net/problem/1946)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<pair<int, int>>` 타입 변수 `rank`를 선언했다.

- 배열을 오름차순 정렬해준다.

- 현재 탐색 원소의 `second` 값이 무조건 이전에 나온 모든 원소의 `second` 값보다 작으면 된다.

  - 이후에 나오는 값들은 현재 원소의 `first` 값보다 작으므로 비교할 필요가 없다.

- 이때까지 나온 원소들의 `second` 값 중 가장 높은 등수(가장 낮은 값)를 저장하는 변수 `high_rank`를 선언하였다.

- `high_rank`가 갱신되는 경우는 문제에서 요구되는 조건을 만족하는 경우기 때문에 `++ret`을 해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tc, n;

int main()
{
    cin >> tc;
    while (tc--) {
        int ret = 1;  // 0번째는 무조건 정답에 포함
        cin >> n;

        vector<pair<int, int>> rank(n);
        for (int i = 0; i < n; ++i) {
            cin >> rank[i].first >> rank[i].second;
        }
        sort(rank.begin(), rank.end());

        int high_rank = rank[0].second;
        for (int i = 1; i < n; ++i) {
            if (high_rank > rank[i].second) {
                high_rank = rank[i].second;
                ++ret;
            }
        }

        cout << ret << '\n';
    }

    return 0;
}
```
