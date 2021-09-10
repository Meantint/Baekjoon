# BOJ_11054 - 가장 긴 바이토닉 부분 수열

&nbsp;

## 문제/코드 링크

- [BOJ_11054 - 가장 긴 바이토닉 부분 수열](https://www.acmicpc.net/problem/11054)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `LIS`를 두 번 사용해준다.

  - 첫번째는 기본 `cost` 배열에다가 사용한다.

  - 두번째는 `cost`를 뒤집은 배열에다가 사용하고 나온 결과 배열 `dpDesc`를 다시 뒤집어준다.

    - 뒤에서 부터 `LIS`를 사용해도된다.

- 정답은 `dpAsc[k] + dpDesc[k] - 1` 값 중 최댓값이다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> cost, dpAsc, dpDesc;
vector<int> lisA, lisD;

int main()
{
    cin >> n;
    cost.resize(n);
    dpAsc.resize(n);
    dpDesc.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    dpAsc[0] = 1;
    lisA.push_back(cost[0]);
    int lisAIdx = 1;
    for (int i = 1; i < n; ++i) {
        int targetIdx = 0;
        for (int j = lisAIdx - 1; j >= 0; --j) {
            if (lisA[j] < cost[i]) {
                targetIdx = j + 1;
                break;
            }
        }
        if (lisAIdx == targetIdx) {
            lisA.push_back(cost[i]);
            ++lisAIdx;
            dpAsc[i] = lisAIdx;
        }
        else {
            lisA[targetIdx] = cost[i];
            dpAsc[i] = targetIdx + 1;
        }
    }

    reverse(cost.begin(), cost.end());
    dpDesc[0] = 1;
    lisD.push_back(cost[0]);
    int lisDIdx = 1;
    for (int i = 1; i < n; ++i) {
        int targetIdx = 0;
        for (int j = lisDIdx - 1; j >= 0; --j) {
            if (lisD[j] < cost[i]) {
                targetIdx = j + 1;
                break;
            }
        }
        if (lisDIdx == targetIdx) {
            lisD.push_back(cost[i]);
            ++lisDIdx;
            dpDesc[i] = lisDIdx;
        }
        else {
            lisD[targetIdx] = cost[i];
            dpDesc[i] = targetIdx + 1;
        }
    }
    reverse(dpDesc.begin(), dpDesc.end());

    int ret = -1;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, dpAsc[i] + dpDesc[i] - 1);
        // cout << "dpAsc, dpDesc : " << dpAsc[i] << ", " << dpDesc[i] << '\n';
    }
    cout << ret << '\n';

    return 0;
}
```
