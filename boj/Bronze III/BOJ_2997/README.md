# BOJ_2997 - 네 번째 수

&nbsp;원래는 오름차순 한 4개의 수 중 2번째 수와 3번째 수인 경우를 다르게 생각해서 풀었는데 더 간단하게 풀 수 있는 방법이 있었다!

- Baekjoon - [네 번째 수](https://www.acmicpc.net/problem/2997)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 3개의 수가 연속된 경우 젤 앞부분이나 젤 뒷부분의 값을 출력하면 된다(필자는 뒷부분 값으로 함).

- 오름차순 한 4개의 수 중 (2 or 3)번째 칸이 비어있는 경우

  - 끝부분 2개와 가운데 2개의 합이 같다는 것을 이용하여 `v[2] - v[0] + v[1]`라는 식으로 네 번째 수를 구하여 출력했다.

## Code

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v(3);

int main()
{
    // 3개의 값 받음
    for (auto& num : v) {
        cin >> num;
    }
    // 오름차순 정렬
    sort(v.begin(), v.end());

    // 3개의 수가 연속될 때
    if (v[2] - v[1] == v[1] - v[0]) {
        cout << v[2] + (v[1] - v[0]) << '\n';
    }
    // 오름차순 한 4개의 수 중 (2 or 3)번째 칸이 비어있는 경우
    else {
        cout << (v[2] + v[0]) - v[1] << '\n';
    }

    return 0;
}
```
