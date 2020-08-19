#include <bits/stdc++.h>

using namespace std;

vector<int> left_card;
vector<int> right_card;
int n;
int dp[2010][2010];

int dfs(int i, int j)
{
    if (i == -1 || j == -1) {
        return 0;
    }

    int& ret = dp[i][j];
    if (ret != -1) {
        return ret;
    }

    if (left_card[i] > right_card[j]) {
        ret = max(ret, dfs(i, j - 1)) + right_card[j];
    }
    ret = max(ret, dfs(i - 1, j - 1));
    ret = max(ret, dfs(i - 1, j));

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        left_card.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        right_card.push_back(num);
    }
    reverse(left_card.begin(), left_card.end());
    reverse(right_card.begin(), right_card.end());
    cout << dfs(n - 1, n - 1) << '\n';

    return 0;
}