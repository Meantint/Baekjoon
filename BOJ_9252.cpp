#include <bits/stdc++.h>

#define PIS pair<int, string>

using namespace std;

string str1, str2;

int main()
{
        cin >> str1 >> str2;

        int size1 = str1.size();
        int size2 = str2.size();
        vector<vector<PIS>> dp(size1 + 1, vector<PIS>(size2 + 1, make_pair(0, "")));
        for (int i = 1; i < size1 + 1; ++i) {
                for (int j = 1; j < size2 + 1; ++j) {
                        if (str1[i - 1] == str2[j - 1]) {
                                dp[i][j].first = dp[i - 1][j - 1].first + 1;
                                dp[i][j].second = dp[i - 1][j - 1].second + str2[j - 1];
                        }
                        else {
                                dp[i][j].first = (dp[i - 1][j].first >= dp[i][j - 1].first) ? dp[i - 1][j].first : dp[i][j - 1].first;
                                dp[i][j].second = (dp[i - 1][j].first >= dp[i][j - 1].first) ? dp[i - 1][j].second : dp[i][j - 1].second;
                        }
                }
        }
        cout << dp[size1][size2].first << '\n'
             << dp[size1][size2].second << '\n';
        /*
	for(int i = 1; i < dp.size(); ++i){
		for(int j = 1; j < dp[0].size(); ++j){
			cout << '(' << dp[i][j].first << ", " << dp[i][j].second << ')' << ' ';
		}
		cout << '\n';
	}
	*/
        return 0;
}
