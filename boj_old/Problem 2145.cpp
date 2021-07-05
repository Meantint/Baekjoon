#include <iostream>

using namespace std;

int recur(int n) {
	int sum = 0;

	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}

	if (sum >= 10) 
		return recur(sum);
	else
		return sum;
}

int main()
{
	int n;
	while (1) {
		cin >> n;

		if (n == 0) break;
		cout << recur(n) << endl;
	}

	return 0;
}
