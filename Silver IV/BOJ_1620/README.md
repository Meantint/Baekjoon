# BOJ_1620 - 나는야 포켓몬 마스터 이다솜

&nbsp;`map`을 두 개 만들지 않아도 될 것 같다.. 풀고 보니!

- Baekjoon - [나는야 포켓몬 마스터 이다솜](https://www.acmicpc.net/problem/1620)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 이름을 `key`로 하는 `pok`과 인덱스를 `key`로 하는 `pok_idx`를 만든다.

- `pok[name] = idx`과 `pok_idx[idx] = name`를 해주고 `++idx`를 해준다.

- `name`을 입력 받고 숫자라면 `pok_idx`에서 찾아주고 문자라면 `pok`에서 찾아준다.

## Code

```cpp
#include <iostream>
#include <map>

using namespace std;

int n, m;
int idx = 1;
string name;
map<string, int> pok;
map<int, string> pok_idx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (n--) {
        cin >> name;
        pok[name] = idx;
        pok_idx[idx] = name;
        ++idx;
    }
    while (m--) {
        cin >> name;
        // 숫자일 경우
        if (name[0] >= '0' && name[0] <= '9') {
            cout << pok_idx[stoi(name)] << '\n';
        }
        // 이름일 경우
        else {
            cout << pok[name] << '\n';
        }
    }

    return 0;
}
```
