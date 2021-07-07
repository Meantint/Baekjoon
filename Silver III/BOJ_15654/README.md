# BOJ_15654 - N과 M (5)

&nbsp;`next_permutation`을 이용해 풀었다.

- Baekjoon - [N과 M (5)](https://www.acmicpc.net/problem/15654)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `do-while`문 안에서 현재 `answer.back()` 값과 이번에 탐색하는 `0 ~ (m - 1)`까지의 인덱스를 저장한 `tmp2`가 다른 경우에만 `answer.push_back(tmp2)`를 해준다. 같은 경우에 `answer.push_back(tmp2)`를 하면 같은 수열이 중복되기 때문이다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> answer;

int main()
{
    cin >> n >> m;

    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    // empty로 인한 문제를 없애기 위해
    answer.push_back(vector<int>(m, -1));
    do {
        vector<int> tmp1 = answer.back();
        vector<int> tmp2;
        bool isSame = true;
        for (int i = 0; i < m; ++i) {
            tmp2.push_back(num[i]);
        }
        if (tmp1 != tmp2) {
            answer.push_back(tmp2);
        }
    } while (next_permutation(num.begin(), num.end()));

    int size = answer.size();
    for (int i = 1; i < size; ++i) {
        for (auto& elem : answer[i]) {
            cout << elem << ' ';
        }
        cout << '\n';
    }

    return 0;
}
```
