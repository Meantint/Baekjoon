# BOJ_10871 - X보다 작은 수

&nbsp;

## 문제/코드 링크

- [BOJ_10871 - X보다 작은 수](https://www.acmicpc.net/problem/10871)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `info`에 `n`개의 값을 넣은 후, `x`와 비교하며 더 작은 수들만 `answer`에 추가해준다.

- `answer`를 순차적으로 출력해주면 정답이다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, x;
vector<int> info;

int main()
{
    cin >> n >> x;
    info.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> info[i];
    }

    vector<int> answer;
    for (int i = 0; i < n; ++i) {
        if (info[i] < x) {
            answer.push_back(info[i]);
        }
    }

    int size = answer.size();
    for (int i = 0; i < size; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}
```
