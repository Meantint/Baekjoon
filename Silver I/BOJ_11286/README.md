# BOJ_11286 - 절댓값 힙

&nbsp;`ios::sync_with_stdio(0)`랑 `cin.tie(0)`를 해줘야하는 문제였다.. ㅡㅡ

## 문제/코드 링크

- [BOJ_11286 - 절댓값 힙](https://www.acmicpc.net/problem/11286)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `min heap` `pq`를 선언한다.

- `pair<int, int>`인 이유

  - `first` : 어떤 값 `k`의 절댓값

  - `second` : 어떤 값 `k`

  - 이런 형태로 선언했을 경우 문제에서 요구하는 순서로 정렬이 된다.

## Code

```cpp
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> n;
    while (n--) {
        int num;
        cin >> num;

        if (num != 0) {
            pq.push(make_pair(abs(num), num));
        }
        else {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}
```
