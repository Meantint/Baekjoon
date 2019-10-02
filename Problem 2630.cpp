#include <iostream>
#include <vector>

using namespace std;

int arr[128][128] = { 0 };
int cnt0 = 0;
int cnt1 = 0;

void recur(int x, int y, int n) {
	int count = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] == 1) {
				count++;
			}
		}
	}
	if (n == 1) {
		if (arr[x][y] == 1) {
			cnt1++;
		}
		else {
			cnt0++;
		}
		return;
	}
	if (count == n * n) {
		cnt1++;
		return;
	}
	else if (count == 0) {
		cnt0++;
	}
	else {
		recur(x, y, n / 2);
		recur(x + n / 2, y, n / 2);
		recur(x, y + n / 2, n / 2);
		recur(x + n / 2, y + n / 2, n / 2);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	recur(0, 0, n);

	cout << cnt0 << endl << cnt1 << endl;

	return 0;
}
