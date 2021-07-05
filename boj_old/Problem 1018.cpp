#include <iostream>
#include <algorithm>

using namespace std;

char arr[52][52];
int N, M;
int minCnt = 2500;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i + 7 < N; ++i) {
		for (int j = 0; j + 7 < M; ++j) {
			int cnt = 0;
			for (int x = i; x < i + 8; ++x) {
				for (int y = j; y < j + 8; ++y) {
					if ((x + y) % 2 == 0 && arr[x][y] == 'B') {
						cnt++;
					}
					else if ((x + y) % 2 == 1 && arr[x][y] == 'W') {
						cnt++;
					}
				}
			}
			minCnt = min({ minCnt, cnt, 64 - cnt});
		}
	}

	cout << minCnt << endl;

	return;
}

int main()
{
	solve();

	return 0;
}
