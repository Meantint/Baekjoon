# BOJ_2920 - 음계

&nbsp;

- Baekjoon - [음계](https://www.acmicpc.net/problem/2920)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 시키는대로 하자.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> asc = {1, 2, 3, 4, 5, 6, 7, 8};
vector<int> desc = {8, 7, 6, 5, 4, 3, 2, 1};

int main()
{
    vector<int> v(8);
    for (auto& n : v) {
        cin >> n;
    }

    // asc과 같다면
    if (v == asc) {
        cout << "ascending" << '\n';
    }
    // desc과 같다면
    else if (v == desc) {
        cout << "descending" << '\n';
    }
    // 둘 다 아니라면
    else {
        cout << "mixed" << '\n';
    }

    return 0;
}
```
