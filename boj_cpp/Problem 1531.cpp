#include <iostream>

using namespace std;

int arr[101][101] = { 0 };
int answer = 0;

int main()
{
	int	n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j <= x2; j++) {
			for (int k = y1; k <= y2; k++) {
				arr[j][k]++;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j] > m) {
				answer++;
			}
		}
	}
	cout << answer << endl;

	return 0;
}
