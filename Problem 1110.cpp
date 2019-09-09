#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0;	        //각 자리수의 합
	int leftnumber, rightnumber;
	int copyNumber;
	int newNumber = -1;	//새로 만들어진 숫자
	int cycleCount = 0;

	cin >> n;
	while (newNumber != n) {
		if (cycleCount == 0)
			copyNumber = n;
		else
			copyNumber = newNumber;
		sum = 0;
		leftnumber = copyNumber % 10;
		while (copyNumber != 0) {
			sum += copyNumber % 10;
			copyNumber /= 10;
		}
		rightnumber = sum % 10;
		newNumber = leftnumber * 10 + rightnumber;
		cycleCount++;
		if (cycleCount > 100)
			break;
	}
	cout << cycleCount << endl;
	return 0;
}
