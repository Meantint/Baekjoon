# BOJ_2559 - 수열

&nbsp;누적 합을 이용하여 풀었다.

- Baekjoon - [수열](https://www.acmicpc.net/problem/2559)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 초기 `answer`의 값을 `arr[0] ~ arr[k - 1]`의 합으로 지정해준다.

- `temp = temp + arr[i] - arr[i - k]`으로 한 칸씩 오른쪽으로 당긴 후 값이 현재 `answer`보다 크다면 `answer`를 갱신 해준다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, k;
int answer;
vector<int> arr;

void solve()
{
    int temp = 0;

    answer = 0;

    for (int i = 0; i < k; ++i) {
        temp += arr[i];
    }
    answer = temp;

    for (int i = k; i < n; ++i) {
        temp += arr[i];
        temp -= arr[i - k];

        if (answer < temp) {
            answer = temp;
        }
    }
}

int main()
{
    cin >> n >> k;
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve();

    cout << answer << '\n';

    return 0;
}
```
