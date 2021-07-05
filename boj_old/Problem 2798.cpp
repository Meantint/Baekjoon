#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> arr(n + 1, 0);
	for (int i = 1; i < arr.size(); i++) {
		cin >> arr[i];
	}

	int max = 0;
	for (int i = 1; i < arr.size() - 2; i++) {
		for (int j = i + 1; j < arr.size() - 1; j++) {
			for (int k = j + 1; k < arr.size(); k++) {
				if (arr[i] + arr[j] + arr[k] > m)	continue;
				else if (arr[i] + arr[j] + arr[k] == m) {
					cout << m << endl;

					return 0;
				}
				else {
					if (max < arr[i] + arr[j] + arr[k]) {
						max = arr[i] + arr[j] + arr[k];
					}
				}
			}
		}
	}

	cout << max << endl;

	return 0;
}
