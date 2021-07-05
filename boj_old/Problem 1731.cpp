#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int answer = 0;

	int n;
	cin >> n;

	vector<int> arr(n, 0);
	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}

	if (arr[2] - arr[1] == arr[1] - arr[0]) {
		cout << arr[arr.size() - 1] + arr[2] - arr[1] << endl;
		return 0;
	}
	else {
		cout << arr[arr.size() - 1] * (arr[2] / arr[1]) << endl;
		return 0;
	}

	return 0;
}
