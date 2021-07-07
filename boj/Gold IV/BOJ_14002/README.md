# BOJ_14002 - 가장 긴 증가하는 부분 수열 4

&nbsp;`LIS(Longest Increasing Subsequence)`를 이용하여 풀었다.

- Baekjoon - [가장 긴 증가하는 부분 수열 4](https://www.acmicpc.net/problem/14002)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 현재 최대 길이를 저장하는 배열 `dp`, `i`번째 원소의 `dp` 최대 값을 저장해놓는 배열 `lis`을 선언했다.

- 문제 푸는 방법만 알면 간단한데, 탐색을 끝내고 난 후의 `dpIdx + 1`이 정답의 크기이다.

- 원소 탐색은 역순으로 `dpIdx`부터 `0`까지 차례대로 찾아서 `answer` 배열에 넣어준 후 출력해준다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;
int* arr;
int* lis;
int* dp;
int dpIdx = -1;

void solve()
{
    dp[++dpIdx] = arr[0];
    lis[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (dp[dpIdx] < arr[i]) {
            dp[++dpIdx] = arr[i];
            lis[i] = dpIdx;
        }
        else {
            int cpIdx = dpIdx;
            while (cpIdx >= 0 && dp[cpIdx] >= arr[i]) {
                --cpIdx;
            }
            dp[++cpIdx] = arr[i];
            lis[i] = cpIdx;
        }
    }

    int* answer = new int[dpIdx + 1];
    int find = dpIdx;
    for (int i = n - 1; i >= 0; --i) {
        if (lis[i] == find) {
            answer[find] = arr[i];
            --find;
        }
        if (find == -1) {
            break;
        }
    }

    cout << dpIdx + 1 << '\n';
    for (int i = 0; i <= dpIdx; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    cin >> n;
    arr = new int[n];
    lis = new int[n];
    dp = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        lis[i] = dp[i] = 0;
    }

    solve();

    return 0;
}
```
