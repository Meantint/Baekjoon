#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> vec(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}

	int start = 1;
	int end = 1;

	while (end <= n) {
		int sum = 0;
		for (int i = start; i <= end; i++) {
			sum += vec[i];
		}

		if (sum == m) {
			answer++;
			end++;
		}
		else if (sum < m)
			end++;
		else
			start++;

		if (start > end)
			end++;
	}

	cout << answer << endl;

	return 0;
}
