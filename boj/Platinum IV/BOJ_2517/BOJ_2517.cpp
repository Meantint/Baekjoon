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