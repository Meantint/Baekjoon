#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int r, c;
	cin >> r >> c;

	vector<vector<int>> arr(r, vector<int>(c, 0));
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> answer(r - 1, vector<int>(c - 1, 0));
	for (int i = 1; i < answer.size(); i++) {
		for (int j = 1; j < answer[0].size(); j++) {
			vector<int> copy(0);
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					copy.push_back(arr[i + x - 1][j + y - 1]);
				}
			}
			sort(copy.begin(), copy.end());

			answer[i][j] = copy[4];
		}
	}

	int num;
	cin >> num;

	int cnt = 0;
	for (int i = 1; i < answer.size(); i++) {
		for (int j = 1; j < answer[0].size(); j++) {
			if (answer[i][j] >= num)
				cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
