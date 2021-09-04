# BOJ_1676 - 팩토리얼 0의 개수

&nbsp;

## 문제/코드 링크

- [BOJ_1676 - 팩토리얼 0의 개수](https://www.acmicpc.net/problem/1676)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `1` ~ `n`까지의 소인수 `5`의 개수가 정답이다.

  - 뒷자리가 `0`이 나오려면 `10`이 곱해져야 하는데 `10 = 2 * 5`이고, `2`의 증가율이 `5`의 증가율 보다 훨씬 빠르기 때문에 `5`의 개수만 세어주면 된다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;
int answer = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp % 5 == 0) {
            ++answer;
            temp /= 5;
        }
    }
    cout << answer << '\n';

    return 0;
}
```
