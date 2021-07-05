#include <iostream>

using namespace std;

int arr1[2];
int arr2[2];
int saveNum1[2];
int saveNum2[2];

void solve() {
	int num1, num2;

	cin >> num1 >> num2;
	saveNum1[0] = num1;
	saveNum2[0] = num2;
	arr1[0]++;
	arr2[0]++;

	for (int i = 0; i < 2; ++i) {
		cin >> num1 >> num2;
		if (saveNum1[0] == num1)	arr1[0]++;
		else {
			arr1[1]++;
			saveNum1[1] = num1;
		}
		if (saveNum2[0] == num2)	arr2[0]++;
		else {
			arr2[1]++;
			saveNum2[1] = num2;
		}
	}

	if (arr1[0] == 1)	cout << saveNum1[0];
	else			cout << saveNum1[1];
	cout << ' ';
	if (arr2[0] == 1)	cout << saveNum2[0];
	else			cout << saveNum2[1];
	cout << endl;

	return;
}

int main()
{
	solve();

	return 0;
}
