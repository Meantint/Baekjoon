#include <bits/stdc++.h>

using namespace std;

long long minAns = 0;
long long maxAns = 0;

int main()
{
        int N;
        cin >> N;

        vector<int> vec(N, 0);
        for (int i = 0; i < N; ++i) {
                cin >> vec[i];
        }
        // + = 0, - = 1, * = 2, / = 3
        vector<int> op;
        for (int i = 0; i < 4; ++i) {
                int num = 0;
                cin >> num;
                for (int j = 0; j < num; ++j) {
                        op.push_back(i);
                }
        }

        long long val = vec[0];
        for (int i = 0; i < N - 1; ++i) {
                if (op[i] == 0) {
                        val += vec[i + 1];
                }
                else if (op[i] == 1) {
                        val -= vec[i + 1];
                }
                else if (op[i] == 2) {
                        val *= vec[i + 1];
                }
                else if (op[i] == 3) {
                        val /= vec[i + 1];
                }
                minAns = maxAns = val;
        }
        do {
                long long val = vec[0];
                for (int i = 0; i < N - 1; ++i) {
                        if (op[i] == 0) {
                                val += vec[i + 1];
                        }
                        else if (op[i] == 1) {
                                val -= vec[i + 1];
                        }
                        else if (op[i] == 2) {
                                val *= vec[i + 1];
                        }
                        else if (op[i] == 3) {
                                val /= vec[i + 1];
                        }
                }
                maxAns = max(maxAns, val);
                minAns = min(minAns, val);
        } while (next_permutation(op.begin(), op.end()));

        cout << maxAns << '\n'
             << minAns << '\n';

        return 0;
}