# BOJ_4949 - 균형잡힌 세상

&nbsp;공백이 있는 한 줄을 입력받으려면 `getline(cin, str)`을 사용하면된다.

## 문제/코드 링크

- [BOJ_4949 - 균형잡힌 세상](https://www.acmicpc.net/problem/4949)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `stack<char>` 변수 `s`를 선언

- `(`, `[`인 경우는 `s.push`를 해준다.

- `)`, `]`인 경우는 각각 `s.top()`이 `(`, `[`이라면 `s.pop()`을 해주고 다른 값이라면 균형잡힌 문자열이 아니므로 `s.push('$')`를 해주고 `break`한다.

- 그 외의 경우 `continue`

## Code

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (getline(cin, str)) {
        if (str == ".") {
            break;
        }

        stack<char> s;
        int size = str.size();
        for (int i = 0; i < size; ++i) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            }
            else if (str[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    s.push('$');
                    break;
                }
            }
            else if (str[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    s.push('$');
                    break;
                }
            }
            else {
                continue;
            }
        }
        if (s.empty()) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }

    return 0;
}
```
