# BOJ_1032 - 명령 프롬프트

&nbsp;범위가 굉장히 작기 때문에 각 인덱스를 기준으로 전체 탐색하면서 모두 같은지만 확인해주면 된다.

- Baekjoon - [명령 프롬프트](https://www.acmicpc.net/problem/1032)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 전체 탐색하면서 문자열들의 특정 인덱스가 모두 같은 경우 그 문자를 `answer`에 넣어주고 하나라도 다른게 있을 경우 `?`를 넣어준다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string answer = "";
vector<string> str_list;

int main()
{
    cin >> n;
    str_list.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> str_list[i];
    }

    int size = str_list[0].size();
    for (int i = 0; i < size; ++i) {
        bool isSame = true;

        char comp = str_list[0][i];
        for (int j = 1; j < n; ++j) {
            if (comp != str_list[j][i]) {
                isSame = false;
                break;
            }
        }

        if (isSame) {
            answer.push_back(comp);
        }
        else {
            answer.push_back('?');
        }
    }

    cout << answer << '\n';

    return 0;
}
```
