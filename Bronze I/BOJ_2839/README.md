# BOJ_2839 - 설탕 배달

&nbsp;

## 문제/코드 링크

- [BOJ_2839 - 설탕 배달](https://www.acmicpc.net/problem/2839)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 3의 배수로 나눠떨어지는 경우 중 5의 개수가 가장 많은 경우가 최솟값이다.

- 3과 5의 조합으로 만들 수 없는 경우 `-1`

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n;
int ret = -1;

int main()
{
    cin >> n;

    int div3 = 0;
    while (0 <= n) {
        if (n % 5 == 0) {
            ret = div3 + n / 5;
            break;
        }
        else {
            n -= 3;
            ++div3;
        }
    }

    cout << ret << '\n';

    return 0;
}
```
