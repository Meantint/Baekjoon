#include <iostream>

using namespace std;

int H, W, N;

void solve() {
	int num1 = N % H;
	int num2;
	if (N % H == 0) {
		num1 = H;
		num2 = N / H;
	}
	else {
		num2 = N / H + 1;
	}

	cout << num1;
	if (num2 >= 10)		cout << num2 << endl;
	else			cout << '0' << num2 << endl;

	return;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> H >> W >> N;
		solve();
	}

	return 0;
}
