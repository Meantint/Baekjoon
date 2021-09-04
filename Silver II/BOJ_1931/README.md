# BOJ_1931 - 회의실 배정

&nbsp;`Greedy`를 이용하여 풀었다. 회의 시작 시간이 회의 끝나는 시간 보다 느린 케이스는 왜 넣어 놨는지 모르겠다 -_-

## 문제/코드 링크

- [BOJ_1931 - 회의실 배정](https://www.acmicpc.net/problem/1931)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 회의 끝나는 시간을 오름차순 정렬 해놓은 함수 `comp`를 만든다.

- 현재 인덱스의 시작 시간이 이전의 종료 시간 보다 더 늦거나 같다면 `prev`를 교체해주고 `++answer` 해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, answer = 1;
vector<PII> v;

bool comp(const PII& p1, const PII& p2)
{
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    PII prev;
    sort(v.begin(), v.end(), comp);
    for (auto& p : v) {
        if (p.first <= p.second) {
            prev = p;
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        // 말이 안되는 경우
        if (v[i].first > v[i].second) {
            continue;
        }
        // 이전 회의실 이용 시간이 지났다면 사용 가능
        if (v[i].first >= prev.second) {
            prev = v[i];
            ++answer;
        }
    }
    cout << answer << '\n';

    return 0;
}
```
