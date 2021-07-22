# BOJ_13904 - 과제

&nbsp;그리디 문제.

- Baekjoon - [과제](https://www.acmicpc.net/problem/13904)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 점수대로 내림차순을 한다.

- 정렬 순서대로 원소를 받아와서 현재 원소의 마감기한 부터 첫번째 날을 순차적으로 탐색하면서 `answer`의 원소 중 아직 값이 들어가지 않은 곳을 탐색하고, 비어있는 곳을 찾았다면 그곳에 현재 점수를 넣어준다.

  - 마감기한 부터 첫번째 날로 거꾸로 탐색하는 이유는 다음과 같다.

    - 내림차순 정렬된 `info` 배열에서는 점수 크기가 큰 순서로 나오기 때문에 현재 원소 이후에 나오는 원소들은 현재 원소보다 무조건 점수가 낮다.

    - 만약 현재 원소를 첫번째 날 부터 탐색을 시작해서 빈 공간에 넣는다면 마감기한이 더 짧고 점수가 더 낮은 원소의 점수가 들어가지 못하는 상황이 발생한다.

      - 첫째 날 부터 탐색하는 경우 첫 번째 원소는 마감기한 값과 상관없이 첫째 날에 마감을 한다. 이런 경우 다음 원소의 마감기한이 하루(첫째 날이 마감기한)라면 원소가 들어가지 못한다.

    - 마감기한부터 역탐색하는 경우는 현재의 원소를 넣을 수 있는 가장 뒤에 넣기 때문에 다음 원소의 마감기한이 더 짧은 경우에도 넣을 수 있는 가능성이 생긴다.

- `answer`에 들어있는 모든 값을 더해주면 정답.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int dead_line;
vector<int> answer;
vector<pair<int, int>> info;

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second) {
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

void solve()
{
    sort(info.begin(), info.end(), comp);
    for (auto cur : info) {
        int idx = cur.first;
        while (0 < idx && answer[idx] != 0) {
            --idx;
        }
        if (idx != 0) {
            answer[idx] = cur.second;
        }
    }

    return;
}

int main()
{
    cin >> n;
    info.resize(n);

    dead_line = 0;
    for (int i = 0; i < n; ++i) {
        cin >> info[i].first >> info[i].second;
        if (dead_line < info[i].first) {
            dead_line = info[i].first;
        }
    }
    answer.resize(dead_line + 1, 0);

    solve();

    int real_answer = 0;
    for (auto ans : answer) {
        real_answer += ans;
    }
    cout << real_answer << '\n';

    return 0;
}
```
