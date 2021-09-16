# BOJ_1550 - 16진수

&nbsp;

## 문제/코드 링크

- [BOJ_1550 - 16진수](https://www.acmicpc.net/problem/1550)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 처음 값을 `string` 타입으로 받으면 연산하기 편하다.

- 각각의 값들이 16진수에서 10진수로 변환했을 때 가지는 값을 `answer`에 더해준다.

- `answer`는 for문을 반복할 때 마다 `16`씩 곱해준다.

  - 16진수를 계산하고 있기 때문에 다음 값이 있을 때 이전의 값들은 자릿수가 올라가는 것이고 16진수이기 때문에 `16`을 곱해주어야 한다.

## Code

```cpp
#include <iostream>
#include <string>

using namespace std;

string n;

int main()
{
    cin >> n;

    int answer = 0;
    for (int i = 0; i < n.size(); ++i) {
        answer *= 16;
        if ('0' <= n[i] && n[i] <= '9') {
            answer += (n[i] - '0');
        }
        else {
            answer += (n[i] - 'A' + 10);
        }
    }
    cout << answer << '\n';

    return 0;
}
```
