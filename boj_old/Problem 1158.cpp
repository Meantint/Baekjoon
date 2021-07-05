#include <iostream>
#include <vector>

using namespace std;

int arr[10000] = { 0 };

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i < n + 1; i++) {
		arr[i] = i;
	}

	cout << '<';
	int cnt = 0;
	int idx = k;
	while (cnt != n) {
		if (arr[idx] != 0) {
			if (cnt == n - 1) {
				cout << idx << '>';
				break;
			}
			else
				cout << idx << ", ";
			cnt++;
			arr[idx] = 0;
		}
		int flag = 0;
		while (flag != k) {
			idx++;
			if (idx > n)
				idx = 1;
			if (arr[idx] != 0) {
				flag++;
			}

		}
	}

	return 0;
}
