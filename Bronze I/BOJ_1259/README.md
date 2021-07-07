# BOJ_1259 - 팰린드롬수

&nbsp;초기화 함수를 만들어봤는데 코드가 간결해서 쓸만한 것 같다.

- Baekjoon - [팰린드롬수](https://www.acmicpc.net/problem/1259)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 비교를 위해 초기화 해야하는 값들을 초기화 해주는 `init` 함수를 만들었다.

- `st == ed`인 경우는 같은 문자를 비교하므로 항상 같기에 검사해줄 필요 없다.

- while문을 돌면서 `s[st] != s[ed]`라면 `isFel = false`을 해주고 `break` 한다.

- while문이 끝났을 때 `isFel == true`라면 팰린드롬 수, `isFel == false`라면 팰린드롬 수가 아니다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int num;
int st, ed;
bool isFel;
string s;

// 값들을 초기화 해주는 함수
void init()
{
    s = to_string(num);
    st = 0;
    ed = s.size() - 1;
    isFel = true;
}

int main()
{
    cin >> num;
    while (num != 0) {
        init();
        // st == ed인 경우는 어차피 같은 문자이므로 검사할 필요가 없다.
        while (st < ed) {
            if (s[st] == s[ed]) {
                ++st;
                --ed;
            }
            else {
                isFel = false;
                break;
            }
        }
        // while문 검사가 끝났을 때 isFel이 true라면 팰린드롬 수.
        if (isFel) {
            cout << "yes" << '\n';
        }
        // isFel이 false라면 팰린드롬 수가 아님.
        else {
            cout << "no" << '\n';
        }
        cin >> num;
    }

    return 0;
}
```
