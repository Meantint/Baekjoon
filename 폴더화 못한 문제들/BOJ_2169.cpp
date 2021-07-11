#include <bits/stdc++.h>

#define NOT_FIND -2112345678

using namespace std;

int n, m;
int dp[1000][1000][3]; // 3번째 index는 이전에 넘어온 방향 0: left, 1: right, 2: top
int cost[1000][1000];
bool isCheck[1000][1000];

int dfs(int x, int y, int direct)
{
    // 기저 사례
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return NOT_FIND;
    }
    // 마지막 부분에 도착했다면
    if (x == n - 1 && y == m - 1) {
        return cost[x][y];
    }
    // 이미 방문한 곳이라면
    // if (isCheck[x][y]) {
    //     return NOT_FIND;
    // }
    // isCheck[x][y] = true;
    int& ret = dp[x][y][direct];
    // 이미 방문한 곳이라면
    if (ret != -1) {
        return ret;
    }
    if (direct == 0) { // 이전에 넘어온 방향이 left
        ret = max(dfs(x, y + 1, 0), dfs(x + 1, y, 2));
    }
    else if (direct == 1) { // 이전에 넘어온 방향이 right
        ret = max(dfs(x, y - 1, 1), dfs(x + 1, y, 2));
    }
    else { // 이전에 넘어온 방향이 top
        ret = max({ dfs(x, y - 1, 1), dfs(x, y + 1, 0), dfs(x + 1, y, 2) });
    }
    ret += cost[x][y];
    // isCheck[x][y] = false;

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    memset(isCheck, 0, sizeof(isCheck));
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cost[i][j];
        }
    }
    cout << dfs(0, 0, 2) << '\n';

    // output

    // cout << '\n';
    // for (int k = 0; k < 3; ++k) {
    //     cout << '\n';
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < m; ++j) {
    //             cout << dp[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }
}

// 처음 아이디어

// #include <bits/stdc++.h>

// #define NOT_FIND -2112345678

// using namespace std;

// int n, m;
// int dp[1000][1000];
// int cost[1000][1000];
// bool isCheck[1000][1000];

// int dfs(int x, int y)
// {
//     // 기저 사례
//     if (x < 0 || x >= n || y < 0 || y >= m) {
//         return NOT_FIND;
//     }
//     // 마지막 부분에 도착했다면
//     if (x == n - 1 && y == m - 1) {
//         return cost[x][y];
//     }
//     // 이미 방문한 곳이라면
//     if (isCheck[x][y]) {
//         return NOT_FIND;
//     }
//     isCheck[x][y] = true;
//     int& ret = dp[x][y];
//     // 이미 방문한 곳이라면
//     if (ret != -1) {
//         return ret;
//     }
//     ret = max({ dfs(x, y - 1), dfs(x, y + 1), dfs(x + 1, y) }) + cost[x][y];
//     isCheck[x][y] = false;

//     return ret;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     memset(dp, -1, sizeof(dp));
//     memset(isCheck, 0, sizeof(isCheck));
//     cin >> n >> m;

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> cost[i][j];
//         }
//     }
//     cout << dfs(0, 0) << '\n';

//     cout << '\n'
//          << "cost" << '\n';
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cout << setw(3) << cost[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     cout << '\n';
//     dp[n - 1][m - 1] = cost[n - 1][m - 1];
//     cout << "dp" << '\n';
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cout << setw(3) << dp[i][j] << ' ';
//         }
//         cout << '\n';
//     }

//     return 0;
// }