# BOJ_1918 - 후위 표기식

&nbsp;문자열 문제가 푸는데 시간이 오래걸리는게 많은 것 같다. 이 문제도 꽤 걸렸다.

## 문제/코드 링크

- [BOJ_1918 - 후위 표기식](https://www.acmicpc.net/problem/1918)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 피연산자, 연산자를 구별하여 `info` 변수에 넣어주었다.

- `(`를 만난 경우 같은 레벨의 `)`을 만날 때까지의 `string` 값을 `temp`에 넣어주고 `temp`에 대해서 `solve` 함수를 재귀 호출해준다.

- 괄호를 없앴다면(혹은 없는 경우) `*`, `/`를 우선 처리해서 `newInfo` 변수에 새로 담아준다.

- 마지막으로 `+`와 `-`만 남았으므로 `string` 변수 `ret`에 차례대로 연산하여 넣어주면 정답이다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solve(string str)
{
    int size = str.size();
    vector<string> info;

    for (int i = 0; i < size; ++i) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            info.push_back("");
            info.back() += str[i];
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            info.push_back("");
            info.back() += str[i];
        }
        else {  // 괄호 없애기 작업
            string temp = "";
            int depth = 1;
            for (int j = i + 1; j < size; ++j) {
                if (str[j] == '(') {
                    ++depth;
                }
                else if (str[j] == ')') {
                    --depth;
                }
                temp += str[j];

                if (depth == 0) {
                    temp.pop_back();
                    i = j;
                    break;
                }
            }

            string newTemp = solve(temp);

            info.push_back(newTemp);
        }
    }

    // *, / 우선 처리
    vector<string> newInfo;
    newInfo.push_back(info[0]);

    int iSize = info.size();
    for (int i = 1; i < iSize; i += 2) {
        if (info[i] == "*" || info[i] == "/") {
            newInfo.back() += info[i + 1];
            newInfo.back() += info[i];
        }
        else {
            newInfo.push_back(info[i]);
            newInfo.push_back(info[i + 1]);
        }
    }

    // +, - 처리
    string ret = newInfo[0];
    int nSize = newInfo.size();
    for (int i = 1; i < nSize; i += 2) {
        ret += newInfo[i + 1];
        ret += newInfo[i];
    }

    return ret;
}

int main()
{
    string str;
    cin >> str;

    cout << solve(str) << '\n';
}
```
