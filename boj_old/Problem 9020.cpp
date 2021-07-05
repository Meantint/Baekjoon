#include <iostream>
#include <string.h>

using namespace std;

int T, n;
int arr[10002];

void solve() {
	for (int i = n / 2; i > 0; --i) {
		if (arr[i] + arr[n - i] == 2) {
			cout << i << ' ' << n - i << endl;
			return;
		}
	}
}

int main()
{
	//memset(arr, 1, sizeof(arr));
	fill_n(arr, sizeof(arr) / sizeof(int), 1);
	arr[1] = 0;
	for (int i = 2; i <= 100; ++i) {
		for (int j = i + 1; j <= 10000; j++) {
			if (arr[i] != 1)	// 이미 소수가 아닌 것으로 판별됐으면
				continue;
			if (j % i == 0) {	// 나누어 떨어지면
				arr[j] = 0;
			}
		}
	}

#if 0
	for (int i = 1; i <= 1000; ++i) {
		cout << "case " << i << " : " << arr[i] << endl;
	}
#endif

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> n;
		solve();
	}

	return 0;
}
