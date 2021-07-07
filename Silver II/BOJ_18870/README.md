# BOJ_18870 - 좌표 압축

&nbsp;`map`을 이용하여 풀었는데 궁금해서 이것저것 찾아보니 `erase`와 `unique`를 쓰는 것이 더 빠르다고 한다. 이유는 찾아봐도 없음.. 아무래도 `map`에서 삽입 연산을 할 때 레드-블랙 트리를 사용하기 때문에 빈번한 삽입이 있을 경우 사용을 안하는게 좋다는 생각을 한다.

- Baekjoon - [좌표 압축](https://www.acmicpc.net/problem/18870)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `c`를 정렬한 후 인덱스 `i`번과 `c`의 `i`번째 인덱스 값과 매칭시켜 `map`에 넣어준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
int idx = 0;
map<int, int> m;
vector<int> v, c;

int main()
{
    cin >> n;
    v.resize(n), c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    c = v;
    sort(c.begin(), c.end());

    for (auto& elem : c) {
        // 똑같은 원소가 없을 때만 실행
        if (m.find(elem) == m.end()) {
            m[elem] = idx;
            ++idx;
        }
    }
    for (auto& elem : v) {
        cout << m[elem] << ' ';
    }
    cout << '\n';

    return 0;
}
```
