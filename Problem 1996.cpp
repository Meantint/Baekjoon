#include <iostream>

using namespace std;

char map[1002][1002] = { 0 };
char newMap[1002][1002] = { 0 };

void fill(int i, int j) {
	if (map[i][j] >= '1' && map[i][j] <= '9') {
		newMap[i][j] = '*';
		return;
	}
	else {
		int sum = 0;
		for (int x = i - 1; x < i + 2; x++) {
			for (int y = j - 1; y < j + 2; y++) {
				if (map[x][y] >= '1' && map[x][y] <= '9') {
					sum += map[x][y] - '0';
					if (sum >= 10) {
						newMap[i][j] = 'M';
						return;
					}
				}
			}
		}
		newMap[i][j] = '0' + sum;
		return;
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fill(i, j);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << newMap[i][j];
		}
		cout << endl;
	}
}
