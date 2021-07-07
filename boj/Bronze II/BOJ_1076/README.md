# BOJ_1076 - 저항

&nbsp;`map`을 한 번 써봤다.

- Baekjoon - [저항](https://www.acmicpc.net/problem/1076)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `answer` = (첫번째 색 \* 10 + 두번째 색) \* 10^(세번째 색)이다.

- `int` 범위를 초과할 수 있기 때문에 `answer`의 범위 설정을 `long long`으로 하였다.

## Code 

```cpp
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

long long answer = 0;
vector<string> v(3);
map<string, int> m = {
    {"black", 0},
    {"brown", 1},
    {"red", 2},
    {"orange", 3},
    {"yellow", 4},
    {"green", 5},
    {"blue", 6},
    {"violet", 7},
    {"grey", 8},
    {"white", 9},
};

int main()
{
    for (int i = 0; i < 3; ++i) {
        cin >> v[i];
    }
    answer = m[v[0]] * 10 + m[v[1]];
    answer *= (long long)pow(10, m[v[2]]);

    cout << answer << '\n';

    return 0;
}
```
