# BOJ_2798 - 블랙잭

&nbsp;

- Baekjoon - [블랙잭](https://www.acmicpc.net/problem/2798)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 완전탐색하면서 선택한 3개의 숫자 합 `sum`이 `answer`에 저장되어 있는 값 보다 `m`에 더 가까운 경우 `answer`를 `sum`으로 바꿔준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int sum;
int answer = -1;
vector<int> v;

int main()
{
    cin >> n >> m;
    v.resize(n);
    for (auto& num : v) {
        cin >> num;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                sum = v[i] + v[j] + v[k];
                // 세 숫자의 합이 원하는 값을 넘어간다면 continue 해준다.
                if (sum > m) {
                    continue;
                }
                // sum이 m보다 작거나 같기 떄문에 answer보다 큰 경우 무조건 m과 더 가깝다.
                else if (answer < sum) {
                    answer = sum;
                }
            }
        }
    }
    cout << answer << '\n';

    return 0;
}
```
