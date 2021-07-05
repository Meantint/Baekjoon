#include <iostream>
#include <algorithm>

using namespace std;

int length[3];

void solve() {
	cin >> length[0] >> length[1] >> length[2];
	while (length[0] != 0 || length[1] != 0 || length[2] != 0) {
		sort(length, length + 3);

		if (length[0] * length[0] + length[1] * length[1] == length[2] * length[2]) {
			cout << "right" << endl;
		}
		else cout << "wrong" << endl;

		cin >> length[0] >> length[1] >> length[2];
	}

	return;
}

int main()
{
	solve();

	return 0;
}
