#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int answer = 0;

	int n, c;
	cin >> n >> c;

	vector<bool> time(c + 1, 0);
	for (int i = 0; i < n; i++) {
		int cycle;
		cin >> cycle;

		for (int j = cycle; j < time.size(); j += cycle) {
			if (!time[j]) {
				time[j] = true;
			}
		}
	}
		
	for (int i = 1; i < time.size(); i++) {
		if (time[i])	answer++;
	}

	cout << answer << endl;

	return 0;
}
