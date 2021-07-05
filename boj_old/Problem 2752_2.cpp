// sort 함수를 사용했을 때
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr(3, 0);

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
