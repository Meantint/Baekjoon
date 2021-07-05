#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	vector<int> arr(n + 1, 0);
	vector<int> num(n + 1, 0);
	for (int i = 1; i < arr.size(); i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sum /= 2;
	for (int i = 2; i < arr.size(); i += 2) {
		sum -= arr[i];
	}
	num[1] = sum;
	for (int i = 2; i < arr.size(); i++) {
		num[i] = arr[i - 1] - num[i - 1];
	}

	for (int i = 1; i < num.size(); i++) {
		cout << num[i] << endl;
	}

	return 0;
}
