# BOJ_9663 - N-Queen

&nbsp;`VSCode`에서 작업을 하는데 `vector<int> point(15)`와 `int point[15]`의 시간차이가 두 배나 났다. `int point[15]`가 더 빠르다고 나왔는데 막상 백준 제출을 해보니 `vector<int> point(15)`가 더 빨랐다.. 시간이 너무 오래걸려서 내도 시간초과 나겠다 하고 원인을 찾고 있었는데 막상 제출해보니 맞다고 해서 어리둥절했다..

- Baekjoon - [N-Queen](https://www.acmicpc.net/problem/9663)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 이전의 왼쪽 대각선, 오른쪽 대각선, 같은 열에 퀸이 있을 경우 `false`를, 아니라면 `true`를 리턴하는 `isCheck` 함수를 만든다.

- 함수 `nQueen`에서 `isCheck(cur)`가 참이라면 퀸을 현재의 위치 `(cur, i)`에 놓고 다음 행에 놓을 퀸을 찾기 위해 `nQueen(cur + 1)`을 실행한다.

## Code

```cpp
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n, answer = 0;
// vector<int> point(15);
int point[15];

bool isCheck(int cur)
{
    for (int i = 0; i < cur; ++i) {
        if (point[cur] == point[i] || cur - i == abs(point[cur] - point[i])) {
            return false;
        }
    }

    return true;
}

void nQueen(int cur)
{
    if (cur == n) {
        ++answer;
    }
    else {
        for (int i = 0; i < n; ++i) {
            point[cur] = i;
            if (isCheck(cur)) {
                nQueen(cur + 1);
            }
        }
    }
}

int main()
{
    cin >> n;

    nQueen(0);

    cout << answer << '\n';

    return 0;
}
```
