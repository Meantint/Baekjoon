#include <bits/stdc++.h>

using namespace std;

void erase(vector<vector<int>>& vec, int x, int y)
{
        vec[x][y] = 0;
        for (int i = 1; i < vec.size(); ++i) {
                if (vec[i][y] == 1) {
                        erase(vec, i, y);
                }
        }
        for (int j = 1; j < vec[0].size(); ++j) {
                if (vec[x][j] == 1) {
                        erase(vec, x, j);
                }
        }
}

int main()
{
        int answer = 0;

        int n, m;
        cin >> n >> m;

        vector<vector<int>> vec(m + 1, vector<int>(n + 1, 0));
        vector<int> truth(n + 1, 0);

        int num;
        cin >> num;
        for (int i = 0; i < num; ++i) {
                int tmp;
                cin >> tmp;

                truth[tmp] = 1;
        }
        for (int i = 0; i < m; ++i) {
                int T;
                cin >> T;
                for (int j = 0; j < T; ++j) {
                        int tmp;
                        cin >> tmp;
                        vec[i + 1][tmp] = 1;
                }
        }

        int size = truth.size();
        for (int i = 1; i < size; ++i) {
                if (truth[i] == 1) {
                        for (int j = 1; j < m + 1; ++j) {
                                if (vec[j][i] == 1) {
                                        erase(vec, j, i);
                                }
                        }
                }
        }
        int row = vec.size();
        int col = vec[0].size();
        for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                        if (vec[i][j] == 1) {
                                ++answer;
                                break;
                        }
                }
        }
        cout << answer << '\n';

        return 0;
}