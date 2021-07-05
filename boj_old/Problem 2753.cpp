#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	if (n % 4 == 0)
	{
		if (n % 100 != 0)		// 4로 나누어떨어지면 윤년
			cout << "1" << endl;
		else if (n % 400 == 0)		// 400으로 나누어떨어지면 윤년
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	else 
		cout << "0" << endl;

	return 0;
}
