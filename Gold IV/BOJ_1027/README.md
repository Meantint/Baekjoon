# BOJ_1027 - 고층 건물

&nbsp;문제 자체는 안 어렵다. 범위에 낚시를 당했다.

- Baekjoon - [고층 건물](https://www.acmicpc.net/problem/1027)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 높이의 최대값이 `1,000,000,000`이기 때문에 `3` 이상 곱하면 `int` 범위를 초과하기 때문에 `long long` 타입을 써줘야 정상적으로 문제가 풀린다.

- `i` 위치에서 `j` 위치의 빌딩이 보인다면 `i`도, `j`도 서로를 볼 수 있는 것이기 때문에 `0`번 빌딩부터 탐색하되 왼쪽에 있는 건물은 탐색하지 않는다.

  - 왼쪽에 있는 건물 탐색하게 되면 중복탐색이 되므로 굳이 할 필요 없다.

  - `i` 빌딩에서 `j` 빌딩을 봤을 때(i < j) 이전까지의 최대 기울기 보다 크다면 `info` 배열을 `push_back`을 통해 갱신시켜주고 `++answer[i]`, `++answer[j]`를 해주고 같거나 작다면 아무것도 하지않는다.

- 2중 for문이 끝났다면 `answer`에는 각각의 빌딩에서 볼 수 있는 총 개수가 담겨있다. 그러므로 `answer` 배열에서 가장 큰 값이 정답이다.

## Code

```cpp
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n;
vector<ll> h;
vector<int> answer;

int main()
{
    cin >> n;
    h.resize(n);
    answer.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    for (ll i = 0; i < n; ++i) {
        vector<pair<int, int>> info;
        for (ll j = i + 1; j < n; ++j) {
            if (info.empty()) {
                info.push_back(make_pair(1, h[j] - h[i]));
                ++answer[i];
                ++answer[j];

                continue;
            }

            if (info.back().second * (j - i) < info.back().first * (h[j] - h[i])) {
                info.push_back(make_pair(j - i, h[j] - h[i]));
                ++answer[i];
                ++answer[j];
            }
        }
    }

    int ret = 0;
    for (auto a : answer) {
        if (ret < a) {
            ret = a;
        }
    }
    cout << ret << '\n';

    return 0;
}
```
