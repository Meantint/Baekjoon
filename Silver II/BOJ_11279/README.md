# BOJ_11279 - 최대 힙

&nbsp;`Priority_Queue`를 이용하여 풀었다.

- Baekjoon - [최대 힙](https://www.acmicpc.net/problem/11279)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `priority_queue<int, vector<int>, less<int>>` 변수 `pq`를 만든다.

- 받은 값이 `0`인 경우

  - `pq.empty()`가 `true`인 경우에는 `0`을 출력한다.

  - `pq.empty()`가 `false`인 경우에는 `pq.top()`을 출력하고 `pq.pop()` 해준다.

- 받은 값이 `0`이 아닌 경우

  - `pq.push()`를 해준다.

## Code

```cpp
#include <iostream>
#include <queue>

using namespace std;

int n, x;
priority_queue<int, vector<int>, less<int>> pq;

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

    return 0;
}
```
