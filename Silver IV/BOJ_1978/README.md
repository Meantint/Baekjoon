# BOJ_1978 - 소수 찾기

&nbsp;

## 문제/코드 링크

- [BOJ_1978 - 소수 찾기](https://www.acmicpc.net/problem/1978)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 에라토스테네스의 채를 이용하여 `1000`이하의 소수 값들을 모두 `prime`에 넣어준다.

- `n`의 값을 입력 받고 `n`의 값만큼 `num`을 입력 받는다.

- `num`이 소수라면 `++answer`를 해준다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
int num;
vector<bool> isPrime(1001, true);
vector<int> prime;

int main()
{
    for (int i = 2; i < 1001; ++i) {
        // i가 소수가 아니라면 continue
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i * 2; j < 1001; j += i) {
            isPrime[j] = false;
        }
        // 여기까지 왔으면 i는 무조건 소수기 때문에 prime에 넣어준다.
        prime.push_back(i);
    }
    cin >> n;
    while (n--) {
        cin >> num;
        for (auto& p : prime) {
            if (p < num) {
                continue;
            }
            else if (p > num) {
                break;
            }
            else {
                ++answer;
                break;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}
```
