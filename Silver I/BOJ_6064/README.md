# BOJ_6064 - 카잉 달력

&nbsp;2D Array로 만들면 크기가 최대 `1,600,000,000`이므로 만드는 것이 불가능하다.

## 문제/코드 링크

- [BOJ_6064 - 카잉 달력](https://www.acmicpc.net/problem/6064)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `x` 값으로 고정시키면 `m`에 대한 정보만 `isVisited`에 담을 수 있다(최대 크기가 `40,000`이므로).

- 이미 방문한 적이 있는 곳에 다시 방문했을 때 사이클을 한 바퀴 돌았지만 정답을 찾을 수 없는 경우라고 판단할 수 있으므로 `ret = -1`을 실행하고 `break` 해준다.

- 위의 경우를 겪기 전에 `target == y`가 `true`인 경우를 찾는 다면 현재의 `ret` 값을 그대로 출력해주면 된다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int tc, n, m, x, y;
vector<bool> isVisited;

int main()
{
    cin >> tc;
    while (tc--) {
        int ret = 0, target;
        cin >> n >> m >> x >> y;
        isVisited.clear();
        isVisited.resize(m + 1, false);

        // base setting
        ret = target = x;
        target %= m;
        if (target == 0) {
            target = m;
        }

        while (1) {
            if (target == y) {  // answer
                break;
            }

            ret += n;
            target += n;
            target %= m;
            if (target == 0) {
                target = m;
            }
            if (isVisited[target]) {
                ret = -1;
                break;
            }
            isVisited[target] = true;
        }
        cout << ret << '\n';
    }

    return 0;
}
```
