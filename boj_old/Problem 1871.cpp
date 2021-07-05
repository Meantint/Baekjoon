#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		int num1, num2 = 0;
		int answer = 0;

		num1 = ((str[0] - 'A') * 26 * 26) + ((str[1] - 'A') * 26) + str[2] - 'A';
		num2 = (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0') * 1;
	
		answer = abs(num1 - num2);

		if (answer <= 100) {
			cout << "nice" << endl;
		}
		else {
			cout << "not nice" << endl;
		}
	}

	return 0;
}
