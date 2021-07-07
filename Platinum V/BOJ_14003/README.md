# BOJ_14003 - 가장 긴 증가하는 부분 수열 5

&nbsp;`LIS` 문제이지만 기존의 `LIS`는 최대 길이만 알 수 있고 그 때의 구성 원소를 제대로 알지 못하기 때문에 인덱스를 따로 저장해주는 배열을 만들었다.

- Baekjoon - [가장 긴 증가하는 부분 수열 5](https://www.acmicpc.net/problem/14003)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 인덱스를 저장하기 위한 배열 `idx`를 선언하였다.

- `i`번째 원소의 값 `arr[i]`가 `lis`에 들어갈 적절한 위치를 찾아 그 위치 인덱스를 `idx[i]`에 저장해준다.

- 최대 길이를 알고 있기 때문에(`lis_idx + 1`) 전체 원소를 역순으로 탐색하면서 인덱스 값이 `lis_idx`인 수 부터 `0`인 수 까지 차례대로 찾아나간다.

- 예를 들어 첫 번째로 `lis_idx` 값과 같은 인덱스를 찾았다면 `answer[lis_idx] = arr[i]`를 실행해준 후 다음으로 인덱스 값이 `--lis_idx`인 수를 탐색한다. 이런 방식으로 `0`까지 탐색한다.

## Code

```cpp
#include <iostream>

using namespace std;

int n, lis_idx = -1;
int arr[1000000];
int lis[1000000];
int idx[1000000];

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // LIS
    lis[++lis_idx] = arr[0];
    idx[0] = lis_idx;
    for (int i = 1; i < n; ++i) {
        // 현재 최대값 보다 더 크다면
        if (lis[lis_idx] < arr[i]) {
            lis[++lis_idx] = arr[i];
            idx[i] = lis_idx;
        }
        // 현재 최대값 보다 더 작다면
        else {
            // 더 작은 것을 찾을 때까지 탐색
            int cp_idx = lis_idx;
            int sav_idx = -1;
            while (cp_idx >= 0) {
                if (lis[cp_idx] >= arr[i]) {
                    sav_idx = cp_idx;
                    --cp_idx;
                }
                else {
                    break;
                }
            }
            lis[sav_idx] = arr[i];
            idx[i] = sav_idx;
        }
    }
    // 정답 찾기 (역순)
    int find_num = lis_idx;
    int* answer = new int[lis_idx + 1];
    for (int i = n - 1; i >= 0; --i) {
        if (idx[i] == find_num) {
            answer[find_num] = arr[i];
            --find_num;

            if (find_num == -1) {
                break;
            }
        }
    }

    // answer
    cout << lis_idx + 1 << '\n';
    for (int i = 0; i <= lis_idx; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}
```
