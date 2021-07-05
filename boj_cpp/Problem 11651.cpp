#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {	// y좌표를 우선으로 오름차순 하는 함수
	if (b[1] != a[1]) {
		return a[1] < b[1];
	}
	else {
		return a[0] < b[0];
	}
}

int main()
{
	int T;
	cin >> T;

	vector<vector<int>> arr(T, vector<int>(2));
	for (int i = 0; i < T; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < 2; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}
