#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> answer(0);
int sum = 0;

int main()
{
	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (pow((int)sqrt(i), 2) == i) {
			answer.push_back(i);
		}
	}

	if (answer.empty()) {
		cout << "-1" << endl;
		return 0;
	}

	for (int i = 0; i < answer.size(); i++) {
		sum += answer[i];
	}

	cout << sum << endl;
	cout << answer[0] << endl;

	return 0;
}
