# BOJ_10816 - 숫자 카드 2

&nbsp;`algorithm`의 `lower_bound`와 `upper_bound`를 이용해서 풀었다.

## 문제/코드 링크

- [BOJ_10816 - 숫자 카드 2](https://www.acmicpc.net/problem/10816)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `n`개의 값을 `v`에 저장한 후 `sort`로 오름차순 정렬해준다.

- 찾고 싶은 값 `f`을 입력받은 후 `upper_bound(v.begin(), v.end(), f)`와 `lower_bound(v.begin(), v.end(), f)`를 빼준 값을 출력한다.

  - `upper_bound(v.begin(), v.end(), f)` : `f` 값을 초과하는 첫번째 `iterator`를 리턴

  - `lower_bound(v.begin(), v.end(), f)` : `f` 값 이상이 되는 첫번째 `iterator`를 리턴

- `upper_bound`에서 `lower_bound`를 빼면 찾는 값의 개수를 구할 수 있다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int f;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.resize(n);
    for (auto& num : v) {
        cin >> num;
    }
    sort(v.begin(), v.end());
    cin >> m;
    while (m--) {
        cin >> f;
        cout << upper_bound(v.begin(), v.end(), f) - lower_bound(v.begin(), v.end(), f) << ' ';
    }

    return 0;
}
```
