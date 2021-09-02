# BOJ_2751 - 수 정렬하기 2

&nbsp;

## 문제/코드 링크

- [BOJ_2751 - 수 정렬하기 2](https://www.acmicpc.net/problem/2751)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `sort()`를 이용하여 받은 값들을 오름차순 정렬해준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for (auto& num : v) {
        cin >> num;
    }
    sort(v.begin(), v.end());
    for (auto& num : v) {
        cout << num << '\n';
    }

    return 0;
}
```
