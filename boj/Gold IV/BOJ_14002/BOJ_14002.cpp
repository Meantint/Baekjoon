#include <iostream>

using namespace std;

int n;
int* arr;
int* lis;
int* dp;
int dpIdx = -1;

void solve()
{
    dp[++dpIdx] = arr[0];
    lis[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (dp[dpIdx] < arr[i]) {
            dp[++dpIdx] = arr[i];
            lis[i] = dpIdx;
        }
        else {
            int cpIdx = dpIdx;
            while (cpIdx >= 0 && dp[cpIdx] >= arr[i]) {
                --cpIdx;
            }
            dp[++cpIdx] = arr[i];
            lis[i] = cpIdx;
        }
    }

    int* answer = new int[dpIdx + 1];
    int find = dpIdx;
    for (int i = n - 1; i >= 0; --i) {
        if (lis[i] == find) {
            answer[find] = arr[i];
            --find;
        }
        if (find == -1) {
            break;
        }
    }

    cout << dpIdx + 1 << '\n';
    for (int i = 0; i <= dpIdx; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    cin >> n;
    arr = new int[n];
    lis = new int[n];
    dp = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        lis[i] = dp[i] = 0;
    }

    solve();

    return 0;
}