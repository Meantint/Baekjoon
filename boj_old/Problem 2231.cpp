#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int sum = i;
		int copyN = i;
		while (copyN != 0) {
			sum += copyN % 10;
			copyN /= 10;
		}
		if (sum == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << '0' << endl;

	return 0;
}
