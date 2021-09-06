# BOJ_11047 - 동전 0

&nbsp;

## 문제/코드 링크

- [BOJ_11047 - 동전 0](https://www.acmicpc.net/problem/11047)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 문제에서 `A(i)`는 `A(i - 1)`의 배수라고 나와있기 때문에 `cost`의 마지막 원소부터 역순으로 탐색하면 가장 작은 개수로 항상 동전을 구성할 수 있다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, k;
int answer = 0;
vector<int> cost;

int main()
{
    cin >> n >> k;
    cost.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    int costIdx = cost.size() - 1;
    while (k != 0) {
        if (cost[costIdx] <= k) {
            answer += (k / cost[costIdx]);
            k %= cost[costIdx];
        }
        else {
            --costIdx;
        }
    }
    cout << answer << '\n';

    return 0;
}
```
