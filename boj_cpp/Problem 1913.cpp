#include <iostream>

using namespace std;

int arr[1000][1000] = { 0 };
int N = 1;
int n;
int cnt = 1;

void fill(int x, int y, int cnt) {
	if (N > n * n) {
		return;
	}

	int i, j;

	if (N == 1) {
		arr[x][y] = N;
		N++;
		fill(x - 1, y, ++cnt);
	}
	else if (cnt % 2 == 0) {
		for (j = y; j < y + cnt; j++) {
			arr[x][j] = N;
			N++;
		}
		j--;
		for (i = x + 1; i < x + cnt; i++) {
			arr[i][j] = N;
			N++;
		}
		fill(i, j, ++cnt);
	}
	else {
		for (j = y; j > y - cnt; j--) {
			arr[x][j] = N;
			N++;
		}
		j++;
		for (i = x - 1; i > x - cnt; i--) {
			arr[i][j] = N;
			N++;
		}
		fill(i, j, ++cnt);
	}

	return;
}

int main()
{
	int pos;
	cin >> n;
	cin >> pos;

	fill(n / 2 + 1, n / 2 + 1, cnt);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i < 1000; i++) {
		for (int j = 1; j < 1000; j++) {
			if (arr[i][j] == pos) {
				cout << i << " " << j << endl;
				break;
			}
		}
	}

	return 0;
}
