#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

int main()
{
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        vector<vector<int>> answer(r2 - r1 + 1, vector<int>(c2 - c1 + 1, 0));
        vector<vector<PII>> vec;
        for (int i = 0; i < r2 - r1 + 1; ++i) {
                vector<PII> v;
                for (int j = 0; j < c2 - c1 + 1; ++j) {
                        v.push_back(make_pair(r1 + i, c1 + j));
                }
                vec.push_back(v);
        }

        int maxLength = 0; // 가장 큰 숫자의 자릿수
        int row = vec.size();
        int col = vec[0].size();
        for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                        int range = max(abs(vec[i][j].first), abs(vec[i][j].second));
                        int oddNum = pow(2 * range + 1, 2); // (n, n)
                        int evenNum = pow(2 * range, 2); // (-n, -n + 1)
                        if (vec[i][j].first == -1 * range && vec[i][j].second == -1 * range + 1) {
                                answer[i][j] = evenNum;
                                maxLength = max(maxLength, (int)to_string(answer[i][j]).size());
                        }
                        else if (vec[i][j].first == range && vec[i][j].second == range) {
                                answer[i][j] = oddNum;
                                maxLength = max(maxLength, (int)to_string(answer[i][j]).size());
                        }
                        else if (vec[i][j].first < range && vec[i][j].second > (-1 * range + 1)) {
                                answer[i][j] = evenNum
                                    - abs(-1 * range - vec[i][j].first) - abs(-1 * range + 1 - vec[i][j].second);
                                maxLength = max(maxLength, (int)to_string(answer[i][j]).size());
                        }
                        else {
                                answer[i][j] = oddNum
                                    - abs(range - vec[i][j].first) - abs(range - vec[i][j].second);
                                maxLength = max(maxLength, (int)to_string(answer[i][j]).size());
                        }
                }
        }

        cout.setf(ios::right);
        // 출력 테스트
        for (int i = 0; i < vec.size(); ++i) {
                /*for (int j = 0; j < vec[0].size(); ++j) {
                        cout << '(' << setw(4) << vec[i][j].first << ", " << setw(4) << vec[i][j].second << ") ";
                }*/
                for (int j = 0; j < vec[0].size(); ++j) {
                        cout << setw(maxLength) << answer[i][j] << ' ';
                }
                cout << '\n';
        }
}