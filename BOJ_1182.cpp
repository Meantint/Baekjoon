#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n, s;
        cin >> n >> s;

        vector<int> vec(n, 0);
        for (int i = 0; i < n; ++i) {
                cin >> vec[i];
        }
        int answer = 0;
        for (int i = 0; i < n; ++i) {
                vector<int> com;
                for (int j = 0; j < i + 1; ++j) {
                        com.push_back(1);
                }
                for (int j = i + 1; j < n; ++j) {
                        com.push_back(0);
                }
                do {
                        int sum = 0;
                        for (int j = 0; j < n; ++j) {
                                if (com[j] == 1)
                                        sum += vec[j];
                        }
                        if (s == sum)
                                ++answer;
                } while (prev_permutation(com.begin(), com.end()));
        }
        cout << answer << '\n';

        return 0;
}