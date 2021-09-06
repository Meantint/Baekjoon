# BOJ_1107 - 리모컨

&nbsp;`Brute Force`와 `BFS`를 사용하는 문제이다.

## 문제/코드 링크

- [BOJ_1107 - 리모컨](https://www.acmicpc.net/problem/1107)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 고장난 버튼을 제외하고 만들 수 있는 모든 조합을 만든다.

- 모든 조합에서 `target` 값까지의 차이를 구한다.

  - 현재 값의 자릿수 만큼 버튼을 누른 것이기 때문에 자릿수도 횟수에 더해줘야한다.

- `line 53`의 `temp`가 가장 작은 경우 또는 기존에 저장되어 있는 `abs(target - 100)`이 정답이다.

## Code

```cpp
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int target, broken;
vector<bool> btn(10, true);

int BFS()
{
    int ret = abs(target - 100);

    vector<bool> isVisited(1000001, false);
    queue<pair<int, int>> q;  // first : current number, second : move count

    for (int i = 0; i < 10; ++i) {
        if (btn[i]) {
            q.push(make_pair(i, 1));
            isVisited[i] = true;
        }
    }
    while (!q.empty()) {
        int cur = q.front().first;
        int curMove = q.front().second;
        q.pop();

        int temp = abs(target - cur) + to_string(cur).size();
        if (ret > temp) {
            ret = temp;
        }

        cur *= 10;
        for (int i = 0; i < 10; ++i) {
            if (btn[i]) {
                int next = cur + i;
                if (next < 1000001 && !isVisited[next]) {
                    q.push(make_pair(next, curMove + 1));
                    isVisited[next] = true;
                }
            }
        }
    }

    return ret;
}

int main()
{
    cin >> target >> broken;
    for (int i = 0; i < broken; ++i) {
        int num;
        cin >> num;

        btn[num] = false;
    }

    cout << BFS() << '\n';

    return 0;
}
```
