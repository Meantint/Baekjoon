&nbsp;오름차순으로 4개의 숫자 `n1`, `n2`, `n3`, `n4` 중 세 개가 주어졌을 때를 구하는 문제. 중간 값이 주어지는 경우는 없는 줄 알고 풀어서 한 번 틀렸다..

#### Baekjoon - [네 번째 수](https://www.acmicpc.net/problem/2997)
#### My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)


## 풀이

- 세 개의 값을 저장하는 `v` 선언, 정답을 저장하는 `answer` 선언

- 먼저 세 개의 수를 받은 후, `sort`로 오름차순 정렬해준다.

- `v[0] - v[1] == v[1] - v[2]`인 경우 세 수는 연속된 수이므로 4번째 큰 수를 출력한다.

- `v[1] - v[0] > v[2] - v[1]`인 경우 구해야 하는 수는 오름차순 기준 2번째 수이다.

- `v[1] - v[0] < v[2] - v[1]`인 경우 구해야 하는 수는 오름차순 기준 3번째 수이다.

## Code
```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int answer;
vector<int> v(3);

int main()
{
    for (int i = 0; i < 3; ++i) {
        cin >> v[i];
    } 
    sort(v.begin(), v.end());
    if (v[0] - v[1] == v[1] - v[2]) {
        answer = v[2] + v[1] - v[0];
    }
    else if (v[1] - v[0] > v[2] - v[1]) {
        answer = v[0] + v[2] - v[1];
    }
    else {
        answer = v[2] - v[1] + v[0];
    }
    cout << answer << '\n';

    return 0;
}
```