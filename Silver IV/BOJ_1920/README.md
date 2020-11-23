# BOJ_1920 - 수 찾기

&nbsp;이진 탐색으로 해도 된다.

- Baekjoon - [수 찾기](https://www.acmicpc.net/problem/1920)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 최악의 경우 `100000 * 100000` 연산을 할 수 있기 때문에 `map`을 이용하여 풀었다.

- `mp.find(num) != mp.end()`가 `true`일 경우 `map` 컨테이너 안에 `num`이라는 `key`값이 존재하는 것이므로 `1`을 출력해준다.

- `mp.find(num) != mp.end()`가 `false`일 경우 `map` 컨테이너 안에 존재하지 않기 때문에 `0`을 출력해준다.

## Code

```cpp
#include <iostream>
#include <map>

using namespace std;

int n, m;
int num;
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        mp[num] = i;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> num;
        // num 숫자가 mp 안에 존재한다면
        if (mp.find(num) != mp.end()) {
            cout << '1' << '\n';
        }
        // 존재하지 않는다면
        else {
            cout << '0' << '\n';
        }
    }

    return 0;
}
```
