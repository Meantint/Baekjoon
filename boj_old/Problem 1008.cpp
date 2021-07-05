#include <iostream>

using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;

	cout << fixed;			// 소수점 아래 값의 표현 개수를 고정하는 표현
	cout.precision(10);		// precision(x) : 소수점 아래를 x로 고정한다.
					// ex) 1/10 을 입력하면 0.1000000000 이 나옴.
					// 기본적으로는 0.1 이 나옴.
	cout << a / b << endl;

	return 0;
}
