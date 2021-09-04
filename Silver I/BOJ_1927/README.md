# BOJ_1927 - 최소 힙

&nbsp;`priority_queue`로 풀면 된다.

## 문제/코드 링크

- [BOJ_1927 - 최소 힙](https://www.acmicpc.net/problem/1927)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 문제에 시키는 대로 `priority_queue`를 이용해 풀면 된다.

## Code

```cpp
#include <iostream>
#include <queue>

using namespace std;

int n, x;
// pq.top()에는 가장 작은 값이 올 수 있도록 greater<int>를 써준다.
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << '0' << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
}
```
