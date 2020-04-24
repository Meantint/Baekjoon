#include <iostream>
#include <vector>
#include <algorithm>

#define PII pair<int, int>

using namespace std;

int N;
int cnt = 0;
vector<int> dp;
vector<PII> v;

int dfs() {
	for (int i = 1; i < v.size(); ++i) {
		if (dp[dp.size() - 1] < v[i].second) {
			dp.push_back(v[i].second);
			continue;
		}
		for (int j = dp.size() - 1; j >= 0; --j) {
			if (dp[j] > v[i].second) {
				if (j == 0) {
					dp[j] = v[i].second;
					break;
				}
				else if (j - 1 >= 0 && dp[j - 1] < v[i].second) {
					dp[j] = v[i].second;
					break;
				}
				else continue;
			}
		}
	}
	return v.size() - dp.size();
}

void solve() {
	cin >> N;
	if (N == 1) {
		cout << '0' << "\n";
		return;
	}
	for (int i = 0; i < N; ++i) {
		int num1, num2;
		cin >> num1 >> num2;

		v.push_back(PII(num1, num2));
	}
	sort(v.begin(), v.end());

	dp.push_back(v[0].second);
	cout << dfs() << "\n";

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}
