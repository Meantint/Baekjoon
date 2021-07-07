#include <bits/stdc++.h>

using namespace std;

int n, m;

int read(vector<vector<int>> vec)
{
        int answer = -1;
        int sum = 0;

        // 일자형
        for (int i = 0; i < n; ++i) { // 'ㅡ'
                for (int j = 0; j < m - 3; ++j) {
                        sum = vec[i][j] + vec[i][j + 1]
                            + vec[i][j + 2] + vec[i][j + 3];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 3; ++i) { // 'ㅣ'
                for (int j = 0; j < m; ++j) {
                        sum = vec[i][j] + vec[i + 1][j]
                            + vec[i + 2][j] + vec[i + 3][j];
                        if (sum > answer)
                                answer = sum;
                }
        }
        // 네모
        for (int i = 0; i < n - 1; ++i) { // 'ㅁ'
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i][j] + vec[i + 1][j]
                            + vec[i][j + 1] + vec[i + 1][j + 1];
                        if (sum > answer)
                                answer = sum;
                }
        }
        // 'ㄴ'자 8가지
        for (int i = 0; i < n - 2; ++i) { // 'ㄴ'
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i][j] + vec[i + 1][j]
                            + vec[i + 2][j] + vec[i + 2][j + 1];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m - 2; ++j) {
                        sum = vec[i][j] + vec[i + 1][j]
                            + vec[i][j + 1] + vec[i][j + 2];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 2; ++i) { // 'ㄱ'
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i][j] + vec[i][j + 1]
                            + vec[i + 1][j + 1] + vec[i + 2][j + 1];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m - 2; ++j) {
                        sum = vec[i + 1][j] + vec[i + 1][j + 1]
                            + vec[i + 1][j + 2] + vec[i][j + 2];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 2; ++i) {
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i][j + 1] + vec[i + 1][j + 1]
                            + vec[i + 2][j + 1] + vec[i + 2][j];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m - 2; ++j) {
                        sum = vec[i][j] + vec[i][j + 1]
                            + vec[i][j + 2] + vec[i + 1][j + 2];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 2; ++i) {
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i][j] + vec[i][j + 1]
                            + vec[i + 1][j] + vec[i + 2][j];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m - 2; ++j) {
                        sum = vec[i][j] + vec[i + 1][j]
                            + vec[i + 1][j + 1] + vec[i + 1][j + 2];
                        if (sum > answer)
                                answer = sum;
                }
        }
        // 'ㄹ'자 4가지
        for (int i = 0; i < n - 2; ++i) {
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i][j] + vec[i + 1][j]
                            + vec[i + 1][j + 1] + vec[i + 2][j + 1];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 2; ++i) {
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i][j + 1] + vec[i + 1][j + 1]
                            + vec[i + 1][j] + vec[i + 2][j];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m - 2; ++j) {
                        sum = vec[i + 1][j] + vec[i][j + 1]
                            + vec[i + 1][j + 1] + vec[i][j + 2];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m - 2; ++j) {
                        sum = vec[i][j] + vec[i][j + 1]
                            + vec[i + 1][j + 1] + vec[i + 1][j + 2];
                        if (sum > answer)
                                answer = sum;
                }
        }
        // 'ㅗ'자 4가지
        for (int i = 0; i < n - 1; ++i) { // 'ㅗ'
                for (int j = 0; j < m - 2; ++j) {
                        sum = vec[i + 1][j] + vec[i][j + 1]
                            + vec[i + 1][j + 1] + vec[i + 1][j + 2];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 2; ++i) { // 'ㅓ'
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i + 1][j] + vec[i][j + 1]
                            + vec[i + 1][j + 1] + vec[i + 2][j + 1];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 1; ++i) { // 'ㅜ'
                for (int j = 0; j < m - 2; ++j) {
                        sum = vec[i][j] + vec[i][j + 1]
                            + vec[i][j + 2] + vec[i + 1][j + 1];
                        if (sum > answer)
                                answer = sum;
                }
        }
        for (int i = 0; i < n - 2; ++i) { // 'ㅏ'
                for (int j = 0; j < m - 1; ++j) {
                        sum = vec[i][j] + vec[i + 1][j]
                            + vec[i + 2][j] + vec[i + 1][j + 1];
                        if (sum > answer)
                                answer = sum;
                }
        }
        return answer;
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
        int answer = -1;
        answer = read(vec);

        cout << answer << '\n';

        return 0;
}