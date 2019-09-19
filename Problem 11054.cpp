#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int answer = 0;

	int n;
	cin >> n;

	vector<vector<int>> arr(n + 1, vector<int>(2, 0));
	vector<vector<int>>  reArr(n + 1, vector<int>(2, 0));
	for (int i = 1; i < arr.size(); i++) {
		cin >> arr[i][1];
		reArr[reArr.size() - i][1] = arr[i][1];
	}

	arr[1][0] = 1;
	for (int i = 2; i < arr.size(); i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i][1] > arr[j][1]) {
				arr[i][0] = max(arr[i][0], arr[j][0] + 1);
			}
		}
		if (arr[i][0] == 0) {
			arr[i][0] = 1;
		}
	}
	reArr[1][0] = 1;
	for (int i = 2; i < reArr.size(); i++) {
		for (int j = 1; j < i; j++) {
			if (reArr[i][1] > reArr[j][1]) {
				reArr[i][0] = max(reArr[i][0], reArr[j][0] + 1);
			}
		}
		if (reArr[i][0] == 0) {
			reArr[i][0] = 1;
		}
	}

	for (int i = 1; i < arr.size(); i++) {
		if (answer < arr[i][0] + reArr[reArr.size() - i][0] - 1) {
			answer = arr[i][0] + reArr[reArr.size() - i][0] - 1;
		}
	}

	cout << answer << endl;

	return 0;
}
