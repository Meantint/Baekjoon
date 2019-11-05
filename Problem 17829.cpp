#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1024][1024] = { 0 };
int answer = 0;
vector<int> vec(0);

void pooling(int size) {
	if (size == 1) {
		answer = arr[0][0];
		return;
	}

	for (int i = 0; i < size / 2; i++) {
		for (int j = 0; j < size / 2; j++) {
			vec.clear();
			vec.push_back(arr[i * 2][j * 2]);
			vec.push_back(arr[i * 2 + 1][j * 2 + 1]);
			vec.push_back(arr[i * 2 + 1][j * 2]);
			vec.push_back(arr[i * 2][j * 2 + 1]);
			sort(vec.begin(), vec.end());
			arr[i][j] = vec[2];
		}
	}

	pooling(size / 2);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	pooling(n);

	cout << answer << endl;

	return 0;
}
