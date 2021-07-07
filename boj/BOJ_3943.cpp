#include <bits/stdc++.h>

using namespace std;

int t;
int max_num = 1;

void dfs(int num)
{
    if (num == 1) {
        return;
    }

    max_num = max(max_num, num);
    if (num % 2 == 0) {
        dfs(num / 2);
    }
    else {
        dfs(3 * num + 1);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> num;
        dfs(num);
        cout << max_num << '\n';
        max_num = 1;
    }

    return 0;
}