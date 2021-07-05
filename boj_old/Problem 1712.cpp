#include <iostream>

using namespace std;

int main()
{
	long long A, B, C;
	cin >> A >> B >> C;

	if (B >= C) {
		cout << "-1" << endl;

		return 0;
	}

	long long i = 0;
	i = A / (C - B) + 1;
	cout << i << endl;;

	return 0;
}
