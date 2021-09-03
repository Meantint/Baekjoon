# BOJ_10773

&nbsp;

## 문제/코드 링크

- [BOJ_10773](https://www.acmicpc.net/problem/10773)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `stack`을 이용해서 풀었다.

- `0`이 나온 경우 `s.empty()`가 `true`가 아닌 경우 `stack.pop()`을 실행해줬다.

  - 문제 자체에서 `0`이 나온 경우 지울 수 있음이 보장되기 때문에 따로 설정할 필요는 없다.

## Code

```cpp
#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (num == 0) {
            if (!s.empty()) {
                s.pop();
            }
        }
        else {
            s.push(num);
        }
    }

    int ret = 0;
    while (!s.empty()) {
        ret += s.top();
        s.pop();
    }

    cout << ret << '\n';

    return 0;
}
```
