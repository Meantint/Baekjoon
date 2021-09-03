# BOJ_10814 - 나이순 정렬

&nbsp;

## 문제/코드 링크

- [BOJ_10814 - 나이순 정렬](https://www.acmicpc.net/problem/10814)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- `vector<tuple<int, string, int>>` 타입 변수 `mem`을 만들어 `(age, name, index)`를 저장한다.

- `comp` 함수를 이용하여 나이순으로 오름차순 정렬이 되도록 해준다.

- `comp` 함수에서 나이가 같은 경우 `index` 순으로 오름차순 정렬이 되도록 만들어준다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int n;
int age;
string name;
vector<tuple<int, string, int>> mem;

bool comp(const tuple<int, string, int>& t1, const tuple<int, string, int>& t2)
{
    // 나이가 똑같은 경우
    if (get<0>(t1) == get<0>(t2)) {
        // 가입한 순으로 정렬해준다.
        return get<2>(t1) < get<2>(t2);
    }
    // 나이가 다르다면 나이순으로 오름차순 정렬해준다.
    return get<0>(t1) < get<0>(t2);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> age >> name;
        mem.push_back(make_tuple(age, name, i));
    }
    sort(mem.begin(), mem.end(), comp);
    for (auto& m : mem) {
        cout << get<0>(m) << ' ' << get<1>(m) << '\n';
    }

    return 0;
}
```
