# BOJ_15829 - Hashing

&nbsp;

## 문제/코드 링크

- [BOJ_15829 - Hashing](https://www.acmicpc.net/problem/15829)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `int` 범위를 벗어나는 경우가 생기므로 값들을 `long long` 타입으로 두고 연산할 때 마다 `MOD`로 나눠준다.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

#define ll long long
#define MOD 1234567891

using namespace std;

int n, r = 31;
string str;

int main()
{
    cin >> n >> str;

    ll ret = 0;
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        ll alpha = str[i] - 'a' + 1;
        for (int j = 0; j < i; ++j) {
            alpha *= (1LL * r);
            alpha %= MOD;
        }
        ret += alpha;
        ret %= MOD;
    }
    cout << ret << '\n';

    return 0;
}
```
