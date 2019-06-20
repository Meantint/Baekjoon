#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b;
		int new_a;			// a의 첫 번째 자릿값을 받는 변수 
		cin >> a >> b;			// a^b의 첫 번째 자릿값을 구해야 함
		new_a = a;

		for (int j = 0; j < b - 1; j++) {
			new_a *= a;
			if (new_a > 9) {	// new_a가 한 자릿수가 아니라면 
				new_a %= 10;	// 나머지만 표시될 수 있도록 나눈다.
			}
		}
		if (new_a == 0)	new_a = 10;
		cout << new_a << endl;
	}

	return 0;
}
