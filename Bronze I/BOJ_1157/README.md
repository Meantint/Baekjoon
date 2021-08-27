# BOJ_1157 - 단어 공부

&nbsp;각각의 알파벳 문자를 카운트를 하는 배열을 만들면 쉽다.

## 문제/코드 링크

- [BOJ_1157 - 단어 공부](https://www.acmicpc.net/problem/1157)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 알파벳 문자를 카운트하는 배열 `alpha[26]`을 만든다.

- for문으로 알파벳을 하나씩 찾아 `alpha`에 카운트 해준다.

- 최대값이 두 개 이상이 아니라면 가장 카운트가 높은 알파벳을 출력한다.

- 최대값이 두 개 이상이라면 `?`를 출력한다.

## Code

```cpp
#include <iostream>
#include <string>

using namespace std;

bool isOne = true;  // 최대값이 하나인지 판별하는 변수
char answer = 'A';
string str;
// 알파벳 카운트
int alpha[26] = {0};

int main()
{
    cin >> str;

    for (auto& c : str) {
        // 소문자일 때
        if (c >= 'a' && c <= 'z') {
            ++alpha[c - 'a'];
        }
        // 대문자일 때
        else if (c >= 'A' && c <= 'Z') {
            ++alpha[c - 'A'];
        }
    }
    for (int i = 1; i < 26; ++i) {
        // 기존의 정답보다 많은 카운트가 됐을 때 -> 갱신
        if (alpha[answer - 'A'] < alpha[i]) {
            answer = i + 'A';
            isOne = true;  // 이전의 최대값이 하나가 아니었을 수 있기 때문에 true로 바꿔준다.
        }
        // 사이즈가 같을 때
        else if (alpha[answer - 'A'] == alpha[i]) {
            isOne = false;  // 하나가 아니므로
        }
    }
    // 최대값이 하나라면
    if (isOne) {
        cout << answer << '\n';
    }
    // 하나가 아니라면
    else {
        cout << '?' << '\n';
    }

    return 0;
}
```
