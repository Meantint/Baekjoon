# BOJ_7568 - 덩치

&nbsp;자기가 몇 명 보다 덩치가 큰지를 세서 `rank`까지 지정해서 계산했는데 틀려서 다시 읽어보니 단순히 `자기보다 덩치가 큰 사람 수 + 1`이 정답이었다...

## 문제/코드 링크

- [BOJ_7568 - 덩치](https://www.acmicpc.net/problem/7568)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 완전탐색하면서 자기보다 덩치가 큰 사람의 수를 구하고 출력해준다.

  - 필자의 경우 초기화에서 미리 `+1` 해줬다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> info;

int main()
{
    cin >> n;
    info = vector<vector<int>>(n, vector<int>(3, 1));
    for (int i = 0; i < n; ++i) {
        cin >> info[i][0] >> info[i][1];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (info[i][0] < info[j][0] && info[i][1] < info[j][1]) {
                ++info[i][2];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << info[i][2] << ' ';
    }
    cout << '\n';

    return 0;
}
```
