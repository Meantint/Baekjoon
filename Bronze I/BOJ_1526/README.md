# BOJ_1526 - 가장 큰 금민수

&nbsp;한 자리수 숫자 10개를 담아놓은 `vector<bool>` 변수 `num`을 선언했다. `num[4] = true`, `num[7] = true`이고 나머지는 모두 `false`이다.

- Baekjoon - [가장 큰 금민수](https://www.acmicpc.net/problem/1526)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `solve` 함수를 살펴보자.

  - 현재 숫자부터 차례대로 검사하면된다(최대 크기가 `1000000`이기 때문에 완전탐색 가능)

  - 현재 숫자의 모든 자릿수를 확인하면서 `4` 또는 `7`로만 이루ㅇ져있으면 `isPerfect = true`로 while문을 탈출하고 이 경우 `answer = i`를 실행한 후 `solve` 함수를 종료한다.

  - 만약 자릿수 중 하나라도 `4` 또는 `7`이 아닌 것이 있으면 `isPerfect = false`이기 때문에 다음 숫자를 탐색하면 된다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, answer;
vector<bool> num(10, false);

void solve()
{
    for (int i = n; i > 3; --i) {
        int temp = i;

        bool isPerfect = true;
        while (temp != 0) {
            if (num[temp % 10]) {
                temp /= 10;
            }
            else {
                isPerfect = false;
                break;
            }
        }
        if (isPerfect) {
            answer = i;
            break;
        }
    }
}

int main()
{
    cin >> n;

    num[4] = num[7] = true;
    solve();

    cout << answer << '\n';

    return 0;
}
```
