# BOJ_2108 - 통계학

&nbsp;뭔가 굉장히 복잡하게 푼 것 같다..

## 문제/코드 링크

- [BOJ_2108 - 통계학](https://www.acmicpc.net/problem/2108)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `answer[0]` : 반올림 해줘야 해서 `cmath` 라이브러리의 `floor` 함수를 사용하였다.

  - `floor` 함수는 내림해주는 함수이므로 원하는 값에 `0.5`를 더해주면 반올림한 효과를 얻을 수 있다.

- `answer[1]` : `info[n / 2]`가 중간 값. 오름차순 혹은 내림차순을 한 경우 한정.

- `answer[2]` : `map<int, int>` 변수 `m`에 모든 값들에 대한 개수를 저장하고 `vector<pair<int, int>>` 타입 변수로 치환(`fq`)하여 값에 대한 개수로 내림차순 정렬하였다. `fq`의 사이즈가 `1` 이상이고 최빈값이 두 개 이상이라면 최빈값 중 값이 두 번째로 작은 값을 넣어주고 그 외의 상황은 최빈값을 넣어준다.

- `answer[3]` : 오름차순을 했다는 가정 하에 `info.back() - info[0]`이다.

## Code

```cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
vector<int> info;
map<int, int> m;
vector<int> answer(4);

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main()
{
    int sum = 0;
    cin >> n;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];

        // 각 값들의 개수 저장을 위한 map<int, int>
        if (m.find(info[i]) == m.end()) {
            m[info[i]] = 1;
        }
        else {
            ++m[info[i]];
        }
        // 산술평균을 위한 sum
        sum += info[i];
    }
    sort(info.begin(), info.end());

    answer[0] = floor(sum / (double)n + 0.5);
    answer[1] = info[n / 2];
    vector<pair<int, int>> fq(m.begin(), m.end());
    sort(fq.begin(), fq.end(), comp);
    if (fq.size() > 1 && fq[0].second == fq[1].second) {
        answer[2] = fq[1].first;
    }
    else {
        answer[2] = fq[0].first;
    }
    answer[3] = info.back() - info[0];

    for (auto ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}
```
