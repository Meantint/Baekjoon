// sort 함수를 사용하지 않을 때
#include <iostream>
#include <vector>

#define MAX 3

using namespace std;

int main()
{
	vector<int> arr(MAX, 0);

	for (int i = 0; i < MAX; i++)
		cin >> arr[i];

	for (int i = 0; i < MAX; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < MAX; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
