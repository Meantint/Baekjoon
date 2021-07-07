# BOJ_1517 - 버블 소트

&nbsp;잘 생각해서 풀었는데 전체 스왑 수가 `int` 범위를 벗어날 수도 있다는 것을 생각못했다.

- Baekjoon - [버블 소트](https://www.acmicpc.net/problem/1517)

- My Baekjoon Code : [https://github.com/Meantint/Baekjoon](https://github.com/Meantint/Baekjoon)

## 풀이

- 분할 정복을 이용하여 풀었다.

- `dc(start, end)`

  - `dc(start, (start + end) / 2)` + `dc((start + end) / 2 + 1, end)`를 수행

  - `[start, (start + end) / 2]`, `[(start + end) / 2 + 1, end]` 범위를 각각 정렬한다.

  - `[start, end]`의 범위를 합친다(정렬한다). 합치는 과정 중에 생기는 위치 변화만큼 `cur_res`에 더해준다.

  - `cur_res`에 더해주는 과정이 모두 중복되기 때문에 `cur_res /= 2`를 해준다.

  - 이후 `res += cur_res`를 해준다.

- 두 개로 나눠서 합치는 과정 중 같은 값이 나올 때가 있는데 스왑을 해주지 않고 두 개의 배열 중 앞쪽에 있는 배열의 값을 먼저 넣어주면 된다. 뒷 배열의 값을 먼저 넣으면 앞 배열의 값이 그 이후에 들어가는데 그 과정자체가 스왑이다.

## Code

```cpp
#include <iostream>

using namespace std;

int n;
int arr[500000];

long long dc(int st, int ed)
{
    // 하나까지 왔다면
    if (st == ed) {
        return 0;
    }
    long long res = 0;

    int mid = (st + ed) / 2;
    res += dc(st, mid);
    res += dc(mid + 1, ed);

    int arr1_idx = st;       // 반으로 쪼갠 것 중 앞부분
    int arr2_idx = mid + 1;  // 반으로 쪼갠 것 중 뒷부분

    int* tmp = new int[ed - st + 1];
    int tmp_idx = -1;

    long long cur_res = 0;  // [st, ed] 까지의 swap 횟수 저장
    while (arr1_idx <= mid && arr2_idx <= ed) {
        // 앞의 값이 더 작다면
        if (arr[arr1_idx] <= arr[arr2_idx]) {
            tmp[++tmp_idx] = arr[arr1_idx];

            int swap_cnt = (st + tmp_idx - arr1_idx);
            cur_res += (swap_cnt > 0) ? swap_cnt : -swap_cnt;
            ++arr1_idx;
        }
        // 값이 같은 경우 swap 하지 않는다.
        // else if (arr[arr1_idx] == arr[arr2_idx]) {
        //     tmp[++tmp_idx] = arr[arr1_idx];
        //     ++arr1_idx;
        // }
        else {
            tmp[++tmp_idx] = arr[arr2_idx];

            int swap_cnt = (st + tmp_idx - arr2_idx);
            cur_res += (swap_cnt > 0) ? swap_cnt : -swap_cnt;
            ++arr2_idx;
        }
    }
    // arr1_idx, arr2_idx 중 하나는 아직 탐색을 완료하지 못했다.
    while (arr1_idx <= mid) {
        tmp[++tmp_idx] = arr[arr1_idx];

        int swap_cnt = (st + tmp_idx - arr1_idx);
        cur_res += (swap_cnt > 0) ? swap_cnt : -swap_cnt;
        ++arr1_idx;
    }
    while (arr2_idx <= ed) {
        tmp[++tmp_idx] = arr[arr2_idx];

        int swap_cnt = (st + tmp_idx - arr2_idx);
        cur_res += (swap_cnt > 0) ? (swap_cnt) : (-swap_cnt);
        ++arr2_idx;
    }
    // 모든 수는 중복되어 count 됐으므로 2로 나눠준다.
    cur_res /= 2;
    res += cur_res;
    // 배열 정렬해준다.
    for (int i = 0; i <= ed - st; ++i) {
        arr[i + st] = tmp[i];
    }

    return res;
}

void solve()
{
    cout << dc(0, n - 1) << '\n';

    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    solve();

    return 0;
}
```
