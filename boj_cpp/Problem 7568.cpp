#include <iostream>

using namespace std;

int N, x, y;
int arr[60][2];

void solve() {
	for (int i = 0; i < N; ++i) {
		int cnt = 1;
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			else {
				if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])	cnt++;
			}
		}
		cout << cnt << ' ';
	}
	cout << endl;

	return;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}

	solve();

	return 0;
}
