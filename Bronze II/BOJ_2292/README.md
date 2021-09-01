# BOJ_2292 - 벌집

&nbsp;

## 문제/코드 링크

- [BOJ_2292 - 벌집](https://www.acmicpc.net/problem/2292)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 테두리가 하나씩 추가될 때 마다 등차수열로 증가하기 때문에 `k`번째 테두리의 상황에서 그 테두리에 속한 최솟값과 최댓값을 알 수 있다. 그러므로 `n`이 최솟값과 최댓값의 사이에 있으면 `k`가 정답일 것이다.

  - 내 문제풀이 기준 `k = 1`은 가장 안쪽의 `1`을 생성하는 테두리이다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;

    // 현재 둘러싸고 있는 테두리의 최솟값 low, 최댓값 high
    int low = 1, high = 1;
    int count = 1;
    while (high < n || n < low) {
        low = high + 1;
        high += (6 * count);
        ++count;
    }

    cout << count << '\n';

    return 0;
}
```
