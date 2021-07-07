#include <bits/stdc++.h>

using namespace std;

int answer = -1;
int safeArea;
int n, m;

void virus(int i, int j, vector<vector<int>>& vec)
{
        if (i < 0 || i >= n || j < 0 || j >= m)
                return;
        if (vec[i][j] != 0)
                return;
        vec[i][j] = 2;

        virus(i + 1, j, vec);
        virus(i - 1, j, vec);
        virus(i, j + 1, vec);
        virus(i, j - 1, vec);

        return;
}

void wall(vector<vector<int>> vec, int cnt)
{
        if (cnt == 0) { // 벽을 3개 쳤다면
                safeArea = 0;
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                                if (vec[i][j] == 2) {
                                        vec[i][j] = 0;
                                        virus(i, j, vec);
                                        vec[i][j] = 2;
                                }
                        }
                }
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                                if (vec[i][j] == 0)
                                        ++safeArea;
                        }
                }
                answer = max(answer, safeArea);
                return;
        }

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        if (vec[i][j] == 0) {
                                vec[i][j] = 1;
                                wall(vec, cnt - 1);
                                vec[i][j] = 0;
                        }
                }
        }
        return;
}

int main()
{
        cin >> n >> m;

        vector<vector<int>> vec(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        cin >> vec[i][j];
                }
        }

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        if (vec[i][j] == 0) {
                                vec[i][j] = 1;
                                wall(vec, 2);
                                vec[i][j] = 0;
                        }
                }
        }
        cout << answer << '\n';

        return 0;
}