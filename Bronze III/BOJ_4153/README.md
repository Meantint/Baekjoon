# BOJ_4153 - 직각삼각형

&nbsp;귀찮아서 `sort`랑 `cmath` 라이브러리를 썼다.

## 문제/코드 링크

- [BOJ_4153 - 직각삼각형](https://www.acmicpc.net/problem/4153)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 오름차순 정렬하면 `info[0] <= info[1] <= info[2]`가 된다. 그러므로 `info[0]^2 + info[1]^2`와 `info[2]^2`를 비교해서 같다면 `right`, 다르다면 `wrong`을 출력해주면 된다.

## Code

```cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> info(3);

int main()
{
    while (1) {
        cin >> info[0] >> info[1] >> info[2];
        if (info[0] == 0 && info[1] == 0 && info[2] == 0) {
            break;
        }

        sort(info.begin(), info.end());  // 오름차순 정렬
        if (pow(info[0], 2) + pow(info[1], 2) == pow(info[2], 2)) {
            cout << "right" << '\n';
        }
        else {
            cout << "wrong" << '\n';
        }
    }

    return 0;
}
```
