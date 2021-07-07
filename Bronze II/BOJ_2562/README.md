# BOJ_2562 - 최댓값

&nbsp;

- Baekjoon - [최댓값](https://www.acmicpc.net/problem/2562)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `max` 값과 그 인덱스를 저장하는 `pair<int, int>` 변수 `answer`를 만든다.

- 순차적으로 탐색하면서 더 큰 값이 나타나면 `answer.first`와 `answer.second`를 갱신해준다.

## Code

```cpp
#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

vector<int> num(9);

// (max_value, idx)
PII answer = make_pair(-1, -1);

int main()
{
    for (auto& n : num) {
        cin >> n;
    }
    for (auto& n : num) {
        if (answer.first < n) {
            answer.first = n;
            answer.second = (&n - &num[0] + 1);
        }
    }
    cout << answer.first << '\n'
         << answer.second << '\n';

    return 0;
}
```
