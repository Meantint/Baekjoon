# BOJ_9375 - 패션왕 신해빈

&nbsp;`map`을 사용해서 풀었다.

## 문제/코드 링크

- [BOJ_9375 - 패션왕 신해빈](https://www.acmicpc.net/problem/9375)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 입지 않는 경우가 있기 때문에 모든 경우를 곱해줄 때 `의상의 개수 + 1`을 곱해준다.

- 하나도 안입는 경우가 경우의 수에 들어가 있기 때문에 정답에서 `1`을 빼준다.

## Code

```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define ll long long

using namespace std;

int tc, n;

int main()
{
    cin >> tc;
    while (tc--) {
        map<string, int> m;
        cin >> n;
        while (n--) {
            string str1, str2;
            cin >> str1 >> str2;

            if (m.find(str2) == m.end()) {
                m[str2] = 1;
            }
            else {
                ++m[str2];
            }
        }

        ll ret = 1;
        for (auto& iter : m) {
            ret *= (1LL * (iter.second + 1));
        }
        cout << ret - 1 << '\n';
    }

    return 0;
}
```
