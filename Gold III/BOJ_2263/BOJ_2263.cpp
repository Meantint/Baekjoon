#include <iostream>

using namespace std;

int n;
int inorder[100000];
int postorder[100000];

void dc(int in_lo, int in_hi, int post_lo, int post_hi)
{
    if (in_lo > in_hi || post_lo > post_hi) {
        return;
    }
    int cur = postorder[post_hi];
    // VLR, V
    cout << cur << ' ';
    // 최소 단위라면
    if (post_lo == post_hi) {
        return;
    }

    int target_idx;
    for (int i = in_lo; i <= in_hi; ++i) {
        if (inorder[i] == cur) {
            target_idx = i;
            break;
        }
    }
    // VLR, L
    dc(in_lo, target_idx - 1, post_lo, post_lo + target_idx - in_lo - 1);
    // VLR, R
    dc(target_idx + 1, in_hi, post_lo + target_idx - in_lo, post_hi - 1);
}

void solve()
{
    dc(0, n - 1, 0, n - 1);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }
    solve();

    return 0;
}