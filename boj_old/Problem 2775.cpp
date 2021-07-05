#include <iostream>

using namespace std;

int T, k, n;
int arr[15][15];

void solve() {
	cout << arr[k][n] << endl;
	
	return;
}

int main()
{
	for (int j = 1; j < 15; ++j) arr[0][j] = j;

	for (int i = 1; i < 15; ++i) {
		for (int j = 1; j < 15; ++j) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> k >> n;
		solve();
	}

	return 0;
}
