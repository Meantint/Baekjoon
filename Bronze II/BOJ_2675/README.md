# BOJ_2675 - 문자열 반복

&nbsp;

- Baekjoon - [문자열 반복](https://www.acmicpc.net/problem/2675)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 시키는대로 하자.

## Code

```cpp
#include <iostream>
#include <string>

using namespace std;

int n, t;
string str;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> str;
        for (auto& s : str) {
            for (int i = 0; i < n; ++i) {
                cout << s;
            }
        }
        cout << '\n';
    }

    return 0;
}
```
