#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	if (n == 1) {
		cout << num[0] * num[0] << endl;
	}
	else {
		cout << num[0] * num[n - 1] << endl;
	}

	return 0;
}
