# SWEA_1206

&nbsp;이 문제를 푼 후 `SWEA_1244`를 풀었는데.. 같은 `D3` 난이도지만 난이도 책정이 객관적이지 않다는 생각이 조금 들었다(아니 많이). 이 문제는 그냥 완전탐색? 인 것 같다.

- SWEA_1206 - [SWEA_1206](https://swexpertacademy.com/main/code/problem/problemList.do?problemTitle=1206&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)

- My SWEA Code : [https://github.com/Meantint/SWEA](https://github.com/Meantint/SWEA)

## 풀이

- 문제 자체에서 왼쪽, 오른쪽 끝 두 칸의 값을 항상 `0`으로 지정해두었기 때문에 범위를 참조할 때 편하다.

- 왼쪽 두 칸, 오른쪽 두 칸의 값들 중 가장 큰 값을 `max_h`에 저장해준다.

- `max_h` 보다 `v[j]`의 값이 큰 경우에 `v[j] - max_h`만큼의 조망이 확보된 것이므로 `answer`에 더해주고 `j += 2`해준다(`v[j]`의 조망이 확보된 것이 왼쪽, 오른쪽 두 칸의 조망을 확보하지 못하게 만든 것과 같으므로).

- 끝까지 완전탐색 하고 출력해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int len;
int answer = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; ++i) {
        answer = 0;

        cin >> len;

        vector<int> v = vector<int>(len, 0);
        for (int j = 0; j < len; ++j) {
            cin >> v[j];
        }
        for (int j = 2; j < len - 2; ++j) {
            int max_h = max({v[j - 2], v[j - 1], v[j + 1], v[j + 2]});
            if (v[j] > max_h) {
                answer += (v[j] - max_h);
                j += 2;  // 두 칸 범위 내에서 조망 확보 불가함(이미 index j가 조망 확보 했기에)
            }
        }

        cout << "#" << i + 1 << ' ' << answer << '\n';
    }

    return 0;
}
```
