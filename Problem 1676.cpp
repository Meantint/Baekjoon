#include <iostream>

using namespace std;

int cnt5 = 0;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 125 == 0) {
			cnt5 += 3;
			continue;
		}
		if (i % 25 == 0) {
			cnt5 += 2;
			continue;
		}
		if (i % 5 == 0) {
			cnt5++;
			continue;
		}
	}

	cout << cnt5 << endl;

	return 0;
}
