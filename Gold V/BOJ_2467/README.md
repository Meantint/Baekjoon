# BOJ_2467 - 용액

&nbsp;투 포인터를 사용하는 문제. 인덱스를 지정할 때 둘 다 오른쪽 또는 왼쪽에 배치하면서 같은 방향으로 이동시키면 정답을 찾지 못하는 경우가 생기므로 왼쪽 끝과 오른쪽 끝에 하나씩 놔두고 시작해야 한다.

## 문제/코드 링크

- [BOJ_2467 - 용액](https://www.acmicpc.net/problem/2467)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 투 포인터를 사용했다.

- 왼쪽을 가리키는 `lo`와 오른쪽을 가리키는 `hi` 사이에 값이 존재하지 않는다면 탐색을 종료한다.

- `lo`, `hi` 사이에 값이 존재하는 경우 `lo`와 `hi` 중 어느 값을 바꿨을 때 더 `0`에 가까워지는지 확인하고 더 가까워지는 것을 선택해주면서 while문이 종료될 때까지 반복한다.

## Code

```cpp
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> info;

int main()
{
    cin >> n;
    info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> info[i];
        // cout << info[i] << '\n';
    }

    int size = info.size();
    int lo = 0, hi = size - 1;
    int now = info[lo] + info[hi];
    int updateAns = 2112345678; // 갱신할 최솟값 저장하는 변수
    pair<int, int> answer = make_pair(-1, -1);  // 정답 저장하는 변수
    while (0 <= hi && lo < size && lo < hi) {
        if (abs(updateAns) > abs(now)) {
            updateAns = now;
            answer = make_pair(info[lo], info[hi]);
        }

        // 사이에 최소 하나 이상 존재한다면
        if (hi - lo > 1) {
            int changeLow = now - info[lo] + info[lo + 1];
            int changeHigh = now - info[hi] + info[hi - 1];

            // lo를 변경했을 때와 hi를 변경했을 때를 비교해서 더 작아지는 값으로 이동한다.
            if (abs(changeLow) < abs(changeHigh)) {
                now = changeLow;
                ++lo;
            }
            else {
                now = changeHigh;
                --hi;
            }
        }
        else {  // 비교 불가한 경우 break
            break;
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';

    return 0;
}
```
