# BOJ_1644 - 소수의 연속합

&nbsp;에라토스테네스의 체로 400만 이하의 소수를 모두 구해 오름차순으로 저장한 후, 투 포인터를 이용해 풀었다.

- Baekjoon - [소수의 연속합](https://www.acmicpc.net/problem/1644)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 이중 for문과 `isPrime`을 이용하여 모든 소수를 구해서 `prime`에 저장한다.

- 투 포인터를 이용한다.

- `ed`가 `prime.size()`와 같거나 더 크다면 바로 `break` 해준다.

- `prime[ed]`의 값이 찾는 값 `n`보다 크다면 더 탐색할 필요가 없으므로 `break` 해준다.

- `cur`: `st ~ ed` 인덱스 구간의 모든 합을 저장해놓은 변수

- `cur > n`: `cur -= prime[st]`를 실행 후 `++st`를 해준다.

- `cur < n`: `++ed`를 해준 후 `cur += prime[ed]`를 실행해준다.

- `cur == n`:  `++answer`를 해준 후 `++ed` & `cur += prime[ed]`를 해준다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
vector<bool> isPrime(4000001, true);
vector<int> prime;

int main()
{
    cin >> n;
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < 4000001; ++i) {
        // i가 소수가 아니라면 넘어간다.
        if (!isPrime[i]) continue;

        for (int j = i * 2; j < 4000001; j += i) {
            isPrime[j] = false;
        }
        // 여기까지 온 i는 무조건 소수이기 때문에 prime에 추가한다.
        prime.push_back(i);
    }

    // 투 포인터, cur: st ~ ed 구간의 합
    int st, ed, cur;
    int pSize = prime.size();
    st = ed = 0;
    cur = prime[0];

    while (1) {
        // 투 포인터의 끝부분이 찾는 값 보다 크다면 더 찾을 필요 없다.
        if (ed >= pSize || prime[ed] > n) {
            break;
        }
        // 찾는 값 보다 작다면 끝부분을 늘려준다.
        if (cur < n) {
            ++ed;
            cur += prime[ed];
        }
        // 찾는 값 보다 크다면 앞부분을 줄여준다.
        else if (cur > n) {
            cur -= prime[st];
            ++st;
        }
        // 찾는 값과 같다면
        else {
            ++answer;
            ++ed;
            cur += prime[ed];
        }
    }
    cout << answer << '\n';

    return 0;
}
```
