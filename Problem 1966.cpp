#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, num;
		cin >> N >> num;

		vector<int> arr(10, 0);
		vector<int> save(N, 0);
		int max = 0;
		int cnt = 1;
		for (int j = 0; j < save.size(); j++) {
			cin >> save[j];

			arr[save[j]]++;
			if (max < save[j]) max = save[j];
		}
		bool check = false;
		while (!check) {
			for (int j = 0; j < save.size(); j++) {
				if (save[j] == max) {
					if (j == num) {
						check = true;
						break;
					}
					else {
						cnt++;
						save[j] = -1;
						arr[max]--;
						if (arr[max] == 0) {
							for (int k = max - 1; k >= 1; k--) {
								if (arr[k] != 0) {
									max = k;
									break;
								}
							}
						}
						continue;
					}
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}
