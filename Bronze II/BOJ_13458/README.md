# BOJ_13458 - 시험 감독

&nbsp;총감독관은 무조건 있어야한다.

## 문제/코드 링크

- [BOJ_13458 - 시험 감독](https://www.acmicpc.net/problem/13458)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 총감독관은 무조건 있어야하므로 각 반의 인원수에서 총감독관이 관리할 수 있는 인원수 만큼 빼준다.

- 필요한 부감독관의 수를 구하는 공식

  - `(info[i] - b - 1) / c + 1`

- 정답이 `int` 범위를 벗어나는 경우가 있으므로 `long long`으로 정답을 구해준다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, b, c;
vector<int> info;
vector<ll> ans;

int main()
{
    cin >> n;
    info.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }
    cin >> b >> c;
    for (int i = 0; i < n; ++i) {
        info[i] -= b;
        if (info[i] > 0) {
            ans[i] = (info[i] - 1) / c + 1;
        }
    }

    ll answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += ans[i];
    }
    answer += (ll)n;
    cout << answer << '\n';

    return 0;
}
```
