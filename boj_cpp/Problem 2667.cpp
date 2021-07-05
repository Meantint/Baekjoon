#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char matrix[27][27] = { 0 };
bool visit[27][27] = { 0 };
int house = 0;
vector<int> houseCount;

void dfs(int i, int j, int n) {
	if ((i < 1 || i > n) || (j < 1 || j > n)) {
		return;
	}
	if (visit[i][j] == true) {
		return;
	}

	visit[i][j] = 1;

	if (matrix[i][j] == '0') {
		return;
	}

	house++;
	dfs(i, j + 1, n);
	dfs(i, j - 1, n);
	dfs(i + 1, j, n);
	dfs(i - 1, j, n);

	return;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == 1) {
				continue;
			}
			else {
				dfs(i, j, n);
				if (house != 0) {
					houseCount.push_back(house);
					house = 0;
				}
			}
		}
	}

	sort(houseCount.begin(), houseCount.end());
	cout << houseCount.size() << endl;
	for (int i = 0; i < houseCount.size(); i++) {
		cout << houseCount[i] << endl;
	}

	return 0;
}
