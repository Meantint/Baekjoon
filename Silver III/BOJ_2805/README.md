# BOJ_2805 - 나무 자르기

&nbsp;이분 탐색 문제

## 문제/코드 링크

- [BOJ_2805 - 나무 자르기](https://www.acmicpc.net/problem/2805)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `1` ~ `*max_element(info.begin(), info.end())` 사이를 이분 탐색하여 정답을 구해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
ll m;
vector<ll> info;

int BS(int low, int high)
{
    int ret = 0;
    int size = info.size();
    int mid;

    while (low <= high) {
        ll sum = 0;

        mid = (low + high) >> 1;
        for (int i = 0; i < size; ++i) {
            if (info[i] - mid < 0) {
                continue;
            }
            sum += (info[i] - mid);
        }

        if (m <= sum) {
            if (ret < mid) {
                ret = mid;
            }
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ret;
}

int main()
{
    cin >> n >> m;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    cout << BS(1, *max_element(info.begin(), info.end())) << '\n';

    return 0;
}
```
