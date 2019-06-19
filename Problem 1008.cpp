#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	cout << fixed;			// 소수점을 고정해서 표현하자는 의미
	cout.precision(9);		// 소수점 자리를 9자리까지 표시
	cout << (double)a / b << endl;

	return 0;
}
