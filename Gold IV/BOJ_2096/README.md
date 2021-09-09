# BOJ_2096 - 내려가기

&nbsp;내가 생각하는 사이즈로는 최대 `100,000(row size) * 3(column size) * 4(byte) * 3(dpMin, dpMax, cost)` 해서 `3,600,000`이니까 `4MB` 이내의 메모리를 사용하는게 아닌가? 생각했는데 안된다. 심지어 `dpMin`, `dpMax`를 `Sliding Window` 처리를 해서 사이즈를 티도 안날정도로 줄였는데도 메모리 초과가 나는게 이상하다.

## 문제/코드 링크

- [BOJ_2096 - 내려가기](https://www.acmicpc.net/problem/2096)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `DP` 사용

- 메모리를 적게 사용해야하고, 우리는 `dp[k]`를 알기 위해 직전의 값 `dp[k - 1]`만 알고 있으면 되기에 모든 정보를 메모리에 저장해놓을 필요는 없다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cost(3);
vector<int> dpMin(3), dpMax(3);

int main()
{
    cin >> n;
    for (int j = 0; j < 3; ++j) {
        cin >> cost[j];
    }
    dpMin = dpMax = cost;
    for (int i = 1; i < n; ++i) {
        cin >> cost[0] >> cost[1] >> cost[2];
        vector<int> temp = dpMin;
        dpMin[0] = min(temp[0], temp[1]) + cost[0];
        dpMin[1] = *min_element(temp.begin(), temp.end()) + cost[1];
        dpMin[2] = min(temp[1], temp[2]) + cost[2];

        temp = dpMax;
        dpMax[0] = max(temp[0], temp[1]) + cost[0];
        dpMax[1] = *max_element(temp.begin(), temp.end()) + cost[1];
        dpMax[2] = max(temp[1], temp[2]) + cost[2];
    }
    cout << *max_element(dpMax.begin(), dpMax.end()) << ' ' << *min_element(dpMin.begin(), dpMin.end()) << '\n';

    return 0;
}
```
