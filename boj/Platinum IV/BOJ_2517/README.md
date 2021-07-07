# BOJ_2517 - 달리기

&nbsp;분할정복을 이용해서 풀었다. 시간을 재면서 풀었는데 꽤 빠르게 그리고 한 번에 정답을 맞춰서 좋았다.

- Baekjoon - [달리기](https://www.acmicpc.net/problem/2517)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- `board[i][0]` : i번째 선수의 실력

- `board[i][1]` : i번째 선수의 가능 랭크

- 원본 배열을 고정시켜서 출력해야 하므로 `indirect`를 사용하였다.

- `dc(lo, mid)`, `dc(mid + 1, hi)`로 분할정복을 한다.

- 이후 왼쪽에서 만들어진 배열(ind의 원소값들만 조정됨)과 오른쪽에서 만들어진 배열을 비교한다.

- 왼쪽에 있을 수록 실력에 비해 높은 등수를 차지할 확률이 높기에 왼쪽의 원소들을 오른쪽으로 이동이 되더라고 최대 등수에 영향이 없다.

- 하지만 오른쪽의 원소들 중 왼쪽의 원소보다 작은 값이 있는 경우 (왼쪽의 남은 인덱스 - 현재 인덱스 + 1) 만큼 최대 등수가 올라간다(2등 -> 4등의 형태이므로 안좋은 것).

- `indirect`로 배열을 변경해야 하기 때문에 왼쪽과 오른쪽을 오름차순 정렬하며 값을 넣고 만들어준 `tmp`의 값으로 `ind` 배열을 변경해준다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;
int board[500000][2];
int ind[500000];

void dc(int lo, int hi)
{
    // 최소 단위
    if (lo == hi) {
        return;
    }
    else {
        int mid = ((lo + hi) >> 1);
        dc(lo, mid);      // 왼쪽
        dc(mid + 1, hi);  // 오른쪽

        int* tmp = new int[hi - lo + 1];
        int tmp_idx = -1;
        int left_idx = lo;
        int right_idx = mid + 1;
        while (left_idx <= mid && right_idx <= hi) {
            // 왼쪽이 오른쪽 보다 작은 경우는 아무 변화 없다.
            if (board[ind[left_idx]][0] < board[ind[right_idx]][0]) {
                // tmp[++tmp_idx] = board[ind[left_idx]][0];
                tmp[++tmp_idx] = ind[left_idx];
                ++left_idx;
            }
            // 오른쪽이 왼쪽 보다 작은 경우는 rank가 증가한다.
            else {
                // tmp[++tmp_idx] = board[ind[right_idx]][0];
                tmp[++tmp_idx] = ind[right_idx];
                board[ind[right_idx]][1] += (mid - left_idx + 1);
                ++right_idx;
            }
        }
        while (left_idx <= mid) {
            tmp[++tmp_idx] = ind[left_idx];
            ++left_idx;
        }
        while (right_idx <= hi) {
            tmp[++tmp_idx] = ind[right_idx];
            ++right_idx;
        }

        for (int i = 0; i <= tmp_idx; ++i) {
            ind[lo + i] = tmp[i];  // indirect의 값 변경해준다.
        }
    }
    return;
}

void solve()
{
    for (int i = 0; i < n; ++i) {
        ind[i] = i;
    }

    dc(0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << board[i][1] << '\n';
    }

    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> board[i][0];
        board[i][1] = 1;  // rank 초기화
    }
    solve();

    return 0;
}
```
