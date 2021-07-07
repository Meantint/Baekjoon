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