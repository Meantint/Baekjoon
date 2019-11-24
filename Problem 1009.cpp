#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;

		int val = 1;
		for (int j = 0; j < b; j++) {
			val *= a;
			val %= 10;
		}
		if (val == 0)	val = 10;
		cout << val << endl;
	}

	return 0;
}
