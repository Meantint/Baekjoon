# BOJ_5525 - IOIOI

&nbsp;

## 문제/코드 링크

- [BOJ_5525 - IOIOI](https://www.acmicpc.net/problem/5525)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `P(N)` 형태가 나올때마다 `N`을 구해서 `info`에 넣어준다.

- 모든 `info`의 원소에 대해 `answer += (info[index] - n + 1)`를 실행해준다(`0 <= index < info.size()`).

  - `info[k] = N`일 때 `N - n + 1`개 만큼의 `P(n)`을 만들 수 있다(`n <= N`).

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, answer = 0;
string str;
vector<int> info;

int main()
{
    cin >> n >> m >> str;
    for (int i = 0; i < m; ++i) {
        int ret = 0;
        if (str[i] == 'I') {
            int temp = i + 1;
            while (temp < m && str.substr(temp, 2) == "OI") {
                ++ret;
                temp += 2;
            }
            info.push_back(ret);
            i = temp - 1;
        }
    }

    int iSize = info.size();
    for (int i = 0; i < iSize; ++i) {
        if (info[i] >= n) {
            answer += (info[i] - n + 1);
        }
    }
    cout << answer << '\n';

    return 0;
}
```
