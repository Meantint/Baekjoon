# BOJ_10250 - ACM 호텔

&nbsp;`n`이 `h`로 나눈 나머지가 `0`일 때와 `0`이 아닐 때 2가지로 나누어 풀어야 한다.

- Baekjoon - [ACM 호텔](https://www.acmicpc.net/problem/10250)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `n`이 `h`로 나누어 떨어질 경우

  - 층수는 `h * 100`이다.

  - 호수는 `(n / h)`이다.

- `n`이 `h`로 나누어 떨어지지 않을 경우

  - 층수는 `(n % h) * 100`이다.

  - 호수는 `(n / h) + 1`이다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int t, h, w, n;
int answer = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> h >> w >> n;
        // n이 h로 나누어 떨어질 경우 가장 높은 층에 머물러야 한다.
        if (n % h == 0) {
            answer = h * 100;
            answer += (n / h);
        }
        // n이 h로 나누어 떨어지지 않을 경우 n / h에 +1을 해줘야 한다.
        else {
            answer = (n % h) * 100;
            answer += (n / h) + 1;
        }
        cout << answer << '\n';
    }

    return 0;
}
```
