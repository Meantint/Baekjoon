&nbsp;쉽게 풀었다.

#### Baekjoon - [긴급 회의](https://www.acmicpc.net/problem/20113)
#### My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)


## 풀이

- 사이즈가 작기 때문에 `vector<pair<int, int>>` 타입 변수 `dp`를 만들어주었다.

	- `dp[i].first` = `i`번째 플레이어가 지목된 횟수

- 입력을 다 받은 후 내림차순으로 정렬하여 가장 큰 수가 한 개라면 그 플레이어의 번호를 리턴한다.

- 가장 큰 수가 두 개 이상이면 `skipped`를 리턴한다.

## Code
```cpp
#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

int n, k;
vector<pii> dp;

int main()
{
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        dp.push_back(make_pair(0, i));
    }
    dp[0].first = -2000;	
    for (int i = 0; i < n; ++i) {
        cin >> k;
        ++dp[k].first;
    }
    sort(dp.begin(), dp.end(), greater<pii>());
    // 공동 두 명 이상 생겼다면
    if (dp[0].first == dp[1].first) {
        cout << "skipped\n";
    }
    else {
        cout << dp[0].second << '\n';
    }

    return 0;
}
```