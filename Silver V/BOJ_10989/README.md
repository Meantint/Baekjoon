# BOJ_10989 - 수 정렬하기 3

&nbsp;수의 범위가 굉장히 작기 때문에 배열 크기를 `10001`로 고정시켜줄 수 있다.

## 문제/코드 링크

- [BOJ_10989 - 수 정렬하기 3](https://www.acmicpc.net/problem/10989)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 입력받은 값을 배열에 넣어준다.

- 오름차순으로 탐색하면서 `info[i]`의 개수만큼 출력해준다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> info(10001, 0);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        ++info[num];
    }
    for (int i = 1; i < 10001; ++i) {
        for (int j = 0; j < info[i]; ++j) {
            cout << i << '\n';
        }
    }

    return 0;
}
```
