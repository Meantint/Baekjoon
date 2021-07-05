#include <iostream>

using namespace std;

void solve(int num) {
	for (int i = 0; i < num * 2; ++i) {
		for (int j = 0; j < num; ++j) {
			if ((i + j) % 2 == 0)	cout << '*';
			else			cout << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;

	if (n == 1) {
		cout << '*' << endl;
	}
	else solve(n);

	return 0;
}
