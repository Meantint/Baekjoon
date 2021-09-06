# BOJ_11659 - 구간 합 구하기 4

&nbsp;`Prefix Sum`을 이용해서 풀었다.

## 문제/코드 링크

- [BOJ_11659 - 구간 합 구하기 4](https://www.acmicpc.net/problem/11659)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 원래의 값을 저장하는 `vector<int>` 변수 `num`과 누적 합을 저장하는 `vector<int>` 변수 `prefix`를 만든다.

- 범위 `i`와 `j`를 받은 후 `prefix[j] - prefix[i - 1]`을 출력한다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, m, i, j;
vector<int> num;
vector<int> prefix;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    num = vector<int>(n);
    prefix = vector<int>(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + num[i - 1];
    }
    while (m--) {
        cin >> i >> j;
        cout << prefix[j] - prefix[i - 1] << '\n';
    }

    return 0;
}
```
