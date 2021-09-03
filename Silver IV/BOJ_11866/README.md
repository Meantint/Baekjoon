# BOJ_11866 - 요세푸스 문제 0

&nbsp;단순한 구현 문제이지만 막상 접근하니 많이 헷갈렸다.

## 문제/코드 링크

- [BOJ_11866 - 요세푸스 문제 0](https://www.acmicpc.net/problem/11866)

- [My Baekjoon Repo](https://github.com/Meantint/Baekjoon)

## 풀이

- 정답 값을 받는 `vector<int>` 타입 변수 `answer`를 만들었다.

- 첫번째 while문 : 모든 숫자를 다 넣을때까지 반복

- 두번째 while문 : 아직 제거가 안 된 사람들을 탐색하는 카운트 `cond`가 `k`와 같을 때까지 반복

- `0`부터 시작했기 때문에 `idx`에 1을 더해줘야 한다.

- 마지막 원소 뒤에는 `, `가 들어가지 않기 때문에 따로 처리해주었다.

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt, idx, cond;
vector<bool> v;
vector<int> answer;

int main()
{
    cin >> n >> k;
    v.resize(n, true);
    idx = k - 1;
    answer.push_back(idx);
    v[idx] = false;
    ++cnt;
    // cnt가 n이 될 때까지 반복
    while (cnt != n) {
        cond = 0;
        while (1) {
            // 아직 제거 안됐다면
            if (v[idx]) {
                ++cond;
                // 만약 cond == k라면
                if (cond == k) {
                    ++cnt;
                    answer.push_back(idx);
                    v[idx] = false;

                    break;
                }
            }
            ++idx;
            idx %= n;
        }
    }

    // 마지막 원소 뒤는 ", "가 안붙기 때문에 size를 하나 작게 받아준다.
    int size = n - 1;
    // output
    cout << '<';
    for (int i = 0; i < size; ++i) {
        cout << answer[i] + 1 << ", ";
    }
    cout << answer.back() + 1 << '>';

    return 0;
}
```
