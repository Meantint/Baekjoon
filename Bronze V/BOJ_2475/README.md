# BOJ_2475 - 검증수

&nbsp;숫자가 작기 때문에 `int` 범위 내에서 해결된다. 그러므로 모두 더해서 10을 나눈 나머지를 출력하면 된다.

## 문제/코드 링크

- [BOJ_2475 - 검증수](https://www.acmicpc.net/problem/2475)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 5개의 수를 제곱한 값을 `answer`에 더해준다.

- `answer %= 10` 해준다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> v(5);
int answer = 0;

int main()
{
    for (int i = 0; i < 5; ++i) {
        cin >> v[i];
    }
    for (auto &num : v) {
        answer += (num * num);
    }
    answer %= 10;
    cout << answer << '\n';

    return 0;
}
```
