&nbsp;에라토스테네스의 체를 이용하여 얻은 소수들을 오름차순으로 저장 후, 투 포인터를 이용하여 풀었다.

#### Baekjoon - [소수의 연속합](https://www.acmicpc.net/problem/1644)
#### My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

<hr>

## 풀이

- `isP[i]` : `i`가 소수 인지 아닌지 판별하는 배열

- `pn` : `2 ~ 4010000` 까지의 소수를 오름차순으로 저장하는 배열

- 에라토스테네스의 체를 이용하여 소수들을 찾아 `pn`에 넣는다.

- 투 포인터로 `pn`을 탐색하며 `n`을 찾을 수 있는 경우 `++answer`를 수행해준다.

<hr>

## Code
```cpp
#include <iostream>
#include <vector>

#define MAX 4000100

using namespace std;

int n, answer = 0;
vector<bool> isP(MAX, true);
vector<int> pn;

int main()
{
    cin >> n;
    for (int i = 2; i < MAX; ++i) {
        // 소수가 아니라면 continue;
        if (!isP[i]) continue;
        for (int j = i + i; j < MAX; j += i) {
            isP[j] = false;
        }
    }
    for (int i = 2; i < MAX; ++i) {
        if (isP[i]) pn.push_back(i);
    }
    int st = 0;
    int ed = 0;
    int val = pn[0];
    int primeSize = pn.size();
    while (st < primeSize && pn[st] <= n) {
        if (val < n) {
            ++ed;
            if (ed == primeSize) break;
            val += pn[ed];
        }
        else if (val == n) {
            ++answer;
            val -= pn[st];
            ++st;
            // st == ed 였던 경우
            if (st > ed) {
                ++ed;
                if (ed == primeSize) break;
                val += pn[ed];
            }
        }
        // val > n
        else {
            val -= pn[st];
            ++st;
            // st == ed 였던 경우
            if (st > ed) {
                ++ed;
                if (ed == primeSize) break;
                val += pn[ed];
            }
        }
    }
    cout << answer << '\n';

    return 0;
}
```

<hr>
