# BOJ_2231 - 분해합

&nbsp;

## 문제/코드 링크

- [BOJ_2231 - 분해합](https://www.acmicpc.net/problem/2231)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 내림차순으로 탐색하면 생성된 값 `ret`을 생성하는 값이 있는지를 저장해놓는 값인 `dp[ret]`이 `0`이 아닌 다른 값이 들어있는지 유무와 상관없이 갱신해주면된다.

  - 오름차순 탐색을 하는 경우 생성된 값 `ret`을 생성하는 값이 있는지를 저장해놓는 값인 `dp[ret]`이 `0`이 아닌 경우 이전에 들어온 값이 있다는 것이고 오름차순 탐색이기 때문에 현재 탐색 중인 값보다는 무조건 작은 값일 것이다.

  - 그러므로 그냥 넘어가야하는 케이스가 생기므로 내림차순에 비해 과정이 하나 더 생긴다고 생각할 수 있다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<int> dp(1000001, 0);

int main()
{
    cin >> n;

    for (int i = 1000000; i > 0; --i) {
        int ret = i;
        string str = to_string(i);
        for (auto ch : str) {
            ret += (ch - '0');
        }

        if (ret <= 1000000) {
            dp[ret] = i;
        }
    }
    cout << dp[n] << '\n';

    return 0;
}
```
