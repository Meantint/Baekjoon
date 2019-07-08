#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int T;
	cin >> T;

	for (int k = 0; k < T; k++) {
		int sum = 0;	// (i, j) 부터 (x, y) 까지의 합을 저장하기 위한 변수

		int i, j, x, y;
		cin >> i >> j >> x >> y;

		for (int cp_i = i; cp_i <= x; cp_i++) {
			for (int cp_j = j; cp_j <= y; cp_j++)
				sum += arr[cp_i - 1][cp_j - 1];
		}

		cout << sum << endl;
	}

	return 0;
}
