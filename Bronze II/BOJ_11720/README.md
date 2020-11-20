# BOJ_11720 - 숫자의 합

&nbsp;`n`은 딱히 필요 없는 듯

- Baekjoon - [숫자의 합](https://www.acmicpc.net/problem/11720)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 각 자릿수들의 합을 구해야 하기 때문에 `string` 타입으로 받는다.

- `str`의 모든 원소 `num`에 대하여 `answer += (num - '0')`해준다.

## Code

```cpp
#include <iostream>
#include <string>

using namespace std;

int n, answer = 0;
string str;

int main()
{
    cin >> n >> str;
    for (auto& num : str) {
        answer += (num - '0');
    }
    cout << answer << '\n';

    return 0;
}
```
