#include <bits/stdc++.h>

using namespace std;

int main()
{
        vector<vector<int>> vec(10, vector<int>(10, 0));
        vector<int> tmp(10, 1);
        vec[0] = tmp;
        for (int i = 1; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                        for (int k = 0; k < j; ++k) {
                                vec[i][j] += vec[i - 1][k];
                        }
                }
        }

        long long num = 0;

        int answer;
        cin >> answer;
        ++answer;
        for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                        answer -= vec[i][j];
                        if (answer <= 0) {
                                answer += vec[i][j];
                                num += (long long)pow(10, i) * (long long)j;
                                if (i != 0)
                                        i -= 2; // 한칸 내림
                                else {
                                        cout << num << '\n';
                                        return 0;
                                }
                                break;
                        }
                }
        }

        cout << "-1\n";
        return 0;
}