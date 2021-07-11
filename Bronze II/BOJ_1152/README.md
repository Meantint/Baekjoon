# BOJ_1152 - 단어의 개수

&nbsp;일반 `cin`으로는 공백을 받지 못하기 때문에 꽤 고민했다.

- Baekjoon - [단어의 개수](https://www.acmicpc.net/problem/1152)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `getline`을 이용해 문자열 전체를 입력받는다.

- `s[i]`가 공백인 경우 `continue`

- `s[i]`가 공백이 아닌 경우 while문을 이용하여 단어가 끝나는 부분으로 인덱스를 변경해주고 `++answer`를 실행한다.

## Code

```cpp
#include <iostream>

using namespace std;

string s;
int answer = 0;

int main()
{
    answer = 0;

    getline(cin, s);

    int s_size = s.size();
    for (int i = 0; i < s_size; ++i) {
        if (s[i] == ' ') {
            continue;
        }

        int temp = i;
        while (temp < s_size && s[temp] != ' ') {
            ++temp;
        }
        i = temp - 1;  // 단어의 끝부분으로 인덱스 변경
        ++answer;
    }

    cout << answer << '\n';

    return 0;
}
```
