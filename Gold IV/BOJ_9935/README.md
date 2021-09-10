# BOJ_9935 - 문자열 폭발

&nbsp;시간초과 날 것 같았는데 제대로 푼 것이었다.

## 문제/코드 링크

- [BOJ_9935 - 문자열 폭발](https://www.acmicpc.net/problem/9935)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 스택이 비어있지 않고 현재 스택 상단 값과 비교하려는 문자열의 마지막 값이 같고, 스택의 사이즈가 비교 문자열의 사이즈보다 큰 경우 `isSame()`을 실행한다.

- `isSame` 함수는 `s2.size()`만큼 스택에서 추출해서 `s2`와 같은 문자열이라면 다시 넣지 않고 `true`를 반환해주고 같은 문자열이 아니라면 다시 원래 상태로 스택에 넣어주고 `false`를 반환한다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s1, s2;
stack<char> s;

bool isSame()
{
    string temp;
    int s2Size = s2.size();
    for (int i = 0; i < s2Size; ++i) {
        temp += s.top();
        s.pop();
    }
    reverse(temp.begin(), temp.end());
    if (temp == s2) {
        return true;
    }
    else {
        for (int i = 0; i < s2Size; ++i) {
            s.push(temp[i]);
        }
        return false;
    }
}

int main()
{
    cin >> s1 >> s2;
    int s1Size = s1.size();
    int s2Size = s2.size();
    for (int i = 0; i < s1Size; ++i) {
        s.push(s1[i]);
        while (!s.empty() && s.top() == s2[s2Size - 1] && s.size() >= s2Size && isSame()) {
        }
    }
    string answer = "";
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    if (answer.empty()) {
        cout << "FRULA\n";
    }
    else {
        reverse(answer.begin(), answer.end());
        cout << answer << '\n';
    }

    return 0;
}
```
