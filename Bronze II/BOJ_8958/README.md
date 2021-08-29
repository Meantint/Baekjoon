# BOJ_8958 - OX퀴즈

&nbsp;

- [BOJ_8958 - OX퀴즈](https://www.acmicpc.net/problem/8958)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `s == 'O'`라면 현재의 `point`를 `answer`에 더해주고, `++point`를 해준다.

- `s == 'X'`라면 `point`의 값을 `1`로 변경해준다.

- 모든 작업이 끝나면 `answer`를 출력해준다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, point = 1, answer = 0;

string str;

int main()
{
    cin >> t;
    while (t--) {
        point = 1;
        answer = 0;

        cin >> str;
        for (auto& s : str) {
            if (s == 'O') {
                answer += point;
                ++point;
            }
            else {
                point = 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}
```
