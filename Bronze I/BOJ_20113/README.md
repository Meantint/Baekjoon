# BOJ_20113 - 긴급 회의

&nbsp;플레이어 번호를 지정하기 위해 `pair<int, int>`를 쓰는 것이 문제를 풀기에 편한 것 같다.

- Baekjoon - [긴급 회의](https://www.acmicpc.net/problem/20113)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 투표 받은 개수와 플레이어 번호를 저장하는 `vector<pair<int, int>>`형 변수 `v`를 선언한다.

- 내림차순 정렬한다.

- `v[0].first == v[1].first`라면 공동 1위가 있는 것이므로 `skipped`를 출력한다.

- `v[0].first != v[1].first`라면 한 명의 1위가 있는 것이므로 `v[0].second`를 출력한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, k;

int main()
{
    cin >> n;
    // (투표 받은 개수, 플레이어 번호)
    vector<PII> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(make_pair(0, i + 1));
    }
    while (n--) {
        cin >> k;
        // 투표를 건너 뛴다면 continue
        if (k == 0) {
            continue;
        }
        ++v[k - 1].first;
    }
    sort(v.begin(), v.end(), greater<PII>());

    // 공동 1위라면
    if (v[0].first == v[1].first) {
        cout << "skipped" << '\n';
    }
    // 혼자 1위라면
    else {
        cout << v[0].second << '\n';
    }

    return 0;
}
```
