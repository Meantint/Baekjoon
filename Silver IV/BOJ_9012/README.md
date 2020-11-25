# BOJ_9012 - 괄호

&nbsp;

- Baekjoon - [괄호](https://www.acmicpc.net/problem/9012)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `check`가 음수가 되는 경우는 탐색 중인 괄호 문자열이 무조건 VPS가 아닌 경우다.

- for문을 종료했을 때 `check == 0`이

  - `true`라면 VPS이므로 `YES`를 출력한다.

  - `false`라면 VPS가 아니므로 `NO`를 출력한다.

## Code

```cpp
#include <iostream>
#include <string>

using namespace std;

int n, check = 0;
string str;

int main()
{
    cin >> n;
    while (n--) {
        check = 0;
        cin >> str;
        for (auto& c : str) {
            if (c == '(') {
                ++check;
            }
            else {
                --check;
            }
            // 이 때까지 탐색한 결과 '('보다 ')'가 더 많은 경우 VPS가 아니다.
            if (check < 0) {
                break;
            }
        }
        // for문이 끝났을 때 check == 0이라면 VPS이다.
        if (check == 0) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
```
