# BOJ_1152 - 단어의 개수

&nbsp;일반 `cin`으로는 공백을 받지 못하기 때문에 꽤 고민했다.

- Baekjoon - [단어의 개수](https://www.acmicpc.net/problem/1152)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `getline`을 이용해 문자열 전체를 입력받는다.

- `공백 -> 문자`일 때 `++answer` & `isBlank = false`를 해준다.

- `공백 -> 공백` & `문자 -> 문자`일 때 `continue` 해준다.

- `문자 -> 공백`일 때 `isBlank = true`를 해준다.

## Code

```cpp
#include <iostream>
#include <string>

using namespace std;

int answer = 0;
string str;
bool isBlank = true;

int main()
{
    getline(cin, str);

    for (auto &c : str) {
        // 이전 문자가 공백이었고
        if (isBlank) {
            // 이번 문자도 공백이라면
            if (c == ' ') {
                continue;
            }
            // 공백이 아니라면
            else {
                ++answer;
                isBlank = false;
            }
        }
        // 이전 문자가 공백이 아니었고
        else {
            // 이번 문자가 공백이라면
            if (c == ' ') {
                isBlank = true;
            }
            // 이번 문자가 공백이 아니라면
            else {
                continue;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}
```
