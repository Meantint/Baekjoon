# BOJ_16953 - A → B

&nbsp;이 문제는 최댓값이 10억이므로 `isVisited` 배열을 사용할 수 없다. 하지만 값이 무조건 커지고 꽤 빠른 속도로 커지는 문제의 조건상 `isVisited`를 선언하지 않고 `BFS` 함수를 만들어주면 된다.

## 문제/코드 링크

- [BOJ_16953 - A → B](https://www.acmicpc.net/problem/16953)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 범위를 벗어나는 경우가 있기 때문에 `long long` 타입으로 선언해준다.

- 구현은 `isVisited`가 없는 `BFS`와 같다.

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

#define ll long long

using namespace std;

ll a, b;

int BFS()
{
    int ret = -1;

    queue<pair<ll, ll>> q;
    q.push(make_pair(a, 1));
    while (!q.empty()) {
        ll cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur > b) {
            continue;
        }
        if (cur == b) {
            ret = dist;
            break;
        }

        q.push(make_pair(cur * 2, dist + 1));
        q.push(make_pair(cur * 10 + 1LL, dist + 1));
    }

    return ret;
}

int main()
{
    cin >> a >> b;

    cout << BFS() << '\n';

    return 0;
}
```
