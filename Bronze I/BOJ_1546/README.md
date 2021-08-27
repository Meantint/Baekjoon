# BOJ_1546 - 평균

&nbsp;수학 문제

## 문제/코드 링크

- [BOJ_1546 - 평균](https://www.acmicpc.net/problem/1546)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 점수들을 저장하는 배열 `v`를 선언한다.

- 가장 높은 점수를 담는 변수 `mx_val`을 선언하고 `v`에서 `mx_val`을 찾는다.

- `((double)(answer * 100) / (double)n) / (double)mx_val`을 해준다.

  - `answer`, `n`, `mx_val` 모두 `int`형 이므로 `double`형 변환을 해줘야 값이 바뀌지 않는다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, mx_val = -1;
int answer = 0;
vector<int> v;

int main()
{
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        answer += v[i];
    }
    for (auto &val : v) {
        mx_val = max(mx_val, val);
    }
    cout << ((double)(answer * 100) / (double)n) / (double)mx_val << '\n';

    return 0;
}
```
