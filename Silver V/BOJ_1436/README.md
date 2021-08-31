# BOJ_1436 - 영화감독 숌

## 문제/코드 링크

- [BOJ_1436 - 영화감독 숌](https://www.acmicpc.net/problem/1436)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 완전탐색해도 시간초과가 나지 않기 때문에 찾고싶은 `n`번째 값을 `1`부터 순서대로 탐색하면서 찾는다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int answer = 0;

int main()
{
    cin >> n;

    int num = 1;
    int count = 0;
    while (n != count) {
        if (to_string(num).find("666") != string::npos) {
            ++count;
            answer = num;
        }
        ++num;
    }

    cout << answer << '\n';

    return 0;
}
```
