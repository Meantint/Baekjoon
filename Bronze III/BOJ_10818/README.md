# BOJ_10818 - 최소, 최대

&nbsp;배열에 저장 후 for문으로 최대, 최소값을 찾으면 된다.

- Baekjoon - [최소, 최대](https://www.acmicpc.net/problem/10818)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 정수 값들을 저장하는 `v`를 만든다.

- for문을 이용해 최솟값, 최댓값을 `answer.first`와 `answer.second`에 갱신해준다.

## Code

```cpp
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;
// (min, max)
PII answer = make_pair(1000100, -1000100);
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for (auto& val : v) {
        cin >> val;
    }
    for (auto& val : v) {
        // 현재까지의 최솟값보다 크다면
        if (val < answer.first) {
            answer.first = val;
        }
        // 현재까지의 최댓값보다 크다면
        if (val > answer.second) {
            answer.second = val;
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';

    return 0;
}
```
