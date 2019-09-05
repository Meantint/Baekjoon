#include <iostream>
using namespace std;

int main()
{
	int a, b;
	int arr[3];
	int moveNum;
	int mul;

	cin >> a >> b;
	mul = a * b;
	for (int i = 0; i < 3; i++)
	{
		moveNum = b % 10;
		arr[i] = moveNum * a;
		b /= 10;
	}
	for (int i = 0; i < 3; i++)
		cout << arr[i] << endl;
	cout << mul << endl;

	return 0;
}
