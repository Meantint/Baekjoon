#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n;
        cin >> n;

        vector<int> com(n, 0); // 조합 위한 벡터 변수
        for (int i = 0; i < n / 2; ++i) {
                com[i] = 1;
        }
        for (int i = n / 2; i < n; ++i) {
                com[i] = 0;
        }
        vector<int> num(n, 0); // 사람 번호
        for (int i = 0; i < n; ++i) {
                num[i] = i;
        }
        vector<vector<int>> vec(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        cin >> vec[i][j];
                }
        }

        int answer = 1000000;
        do {
                vector<int> teamStart;
                vector<int> teamLink;
                int teamStartPt = 0;
                int teamLinkPt = 0;
                for (int i = 0; i < n; ++i) {
                        if (com[i] == 1)
                                teamStart.push_back(i);
                        else
                                teamLink.push_back(i);
                }
                for (int i = 0; i < n / 2; ++i) {
                        for (int j = 0; j < n / 2; ++j) {
                                if (i == j)
                                        continue;
                                teamStartPt += vec[teamStart[i]][teamStart[j]];
                                teamLinkPt += vec[teamLink[i]][teamLink[j]];
                        }
                }
                answer = min(answer, abs(teamStartPt - teamLinkPt));
        } while (prev_permutation(com.begin(), com.end()));

        cout << answer << '\n';

        return 0;
}