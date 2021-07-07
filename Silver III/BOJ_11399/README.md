# BOJ_11399 - ATM

&nbsp;오름차순 정렬해서 풀어주면 된다.

- Baekjoon - [ATM](https://www.acmicpc.net/problem/11399)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 누적 값을 저장하는 `v`를 만들고 누적된 값을 저장해준다.

- `v`의 모든 원소를 `answer`에 더해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; ++i) {
        v[i] += v[i - 1];
    }
    for (auto& num : v) {
        answer += num;
    }
    cout << answer << '\n';

    return 0;
}
```
