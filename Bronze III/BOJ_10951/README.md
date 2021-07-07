# BOJ_10951 - A+B - 4

&nbsp;`input.txt` 파일과 `output.txt` 파일로 풀었더니 전혀 이상이 없어서 제출했는데 틀렸다.. `input.txt`로 받는 경우는 알아서 끝내주기 떄문인듯하다. `cin.eof()`는 `cin`으로 입력 받은게 없다면 `true`를 출력하는 함수다.

- Baekjoon - [A+B - 4](https://www.acmicpc.net/problem/10951)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `cin`으로 부터 아무것도 받지 못했다면 `break`해준다.

- `cin`으로 값을 받았다면 출력해준다.

## Code

```cpp
// cin.eof()가 제대로 출력됐는지 보기 위해서는 input.txt에 빈 개행을 하나 넣어줘야한다.
#include <iostream>

using namespace std;

int n, a, b;

int main()
{
    while (1) {
        cin >> a >> b;
        // cin.eof(): cin으로 받은게 없다면 true
        if (cin.eof()) {
            break;
        }
        cout << a + b << '\n';
    }

    return 0;
}
```
