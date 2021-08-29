# BOJ_3052 - 나머지

&nbsp;

## 문제/코드 링크

- [BOJ_3052 - 나머지](https://www.acmicpc.net/problem/3052)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `algorithm` 라이브러리의 `erase`와 `unique`를 이용해 중복 원소 제거를 해주었다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int num;
vector<int> answer;

int main()
{
    for (int i = 0; i < 10; ++i) {
        cin >> num;
        answer.push_back(num % 42);
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    cout << answer.size() << '\n';

    return 0;
}
```
