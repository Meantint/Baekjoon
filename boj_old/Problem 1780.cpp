#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int countMinus1 = 0;
int count0 = 0;
int count1 = 0;
vector<vector<int>> map(pow(3, 7), vector<int>(pow(3, 7), 0));

void print(int x, int y, int N) {
	if (N == 1) {
		if (map[x][y] == -1) {
			countMinus1++;
			return;
		}
		else if (map[x][y] == 0) {
			count0++;
			return;
		}
		else {
			count1++;
			return;
		}
	}
	int cnt0 = 0;
	int cnt1 = 0;
	int cntMinus1 = 0;

	int saveNum = map[x][y];
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j] != saveNum) {
				print(x, y, N / 3);
				print(x + N / 3, y, N / 3);
				print(x + 2 * N / 3, y, N / 3);
				print(x, y + N / 3, N / 3);
				print(x + N / 3, y + N / 3, N / 3);
				print(x + 2 * N / 3, y + N / 3, N / 3);
				print(x, y + 2 * N / 3, N / 3);
				print(x + N / 3, y + 2 * N / 3, N / 3);
				print(x + 2 * N / 3, y + 2 * N / 3, N / 3);
				return;
			}
		}
	}
	if (saveNum == -1) {
		countMinus1++;
		return;
	}
	else if (saveNum == 0) {
		count0++;
		return;
	}
	else {
		count1++;
		return;
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	print(0, 0, N);

	cout << countMinus1 << endl << count0 << endl << count1 << endl;

	return 0;
}
