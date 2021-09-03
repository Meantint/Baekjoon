# BOJ_11650 - 좌표 정렬하기

&nbsp;

## 문제/코드 링크

- [BOJ_11650 - 좌표 정렬하기](https://www.acmicpc.net/problem/11650)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<pair<int, int>>` 타입 변수 `point`를 만들어 값들을 저장해준다.

- x좌표를 기준으로 오름차순 정렬해주고, x좌표가 같을 시 y좌표를 기준으로 오름차순 정렬해주는 `comp` 함수를 만든다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;
vector<PII> point;

bool comp(const PII& p1, const PII& p2)
{
    // p1과 p2의 x좌표가 같다면
    if (p1.first == p2.first) {
        // p1과 p2의 y좌표를 기준으로 오름차순 정렬해준다.
        return p1.second < p2.second;
    }
    // p1과 p2의 x좌표가 같지 않다면 x좌표를 기준으로 오름차순 정렬해준다.
    return p1.first < p2.first;
}

int main()
{
    cin >> n;
    point.resize(n);
    for (auto& p : point) {
        cin >> p.first >> p.second;
    }
    sort(point.begin(), point.end(), comp);
    for (auto& p : point) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
```
