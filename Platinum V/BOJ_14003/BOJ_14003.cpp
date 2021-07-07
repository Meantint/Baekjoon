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