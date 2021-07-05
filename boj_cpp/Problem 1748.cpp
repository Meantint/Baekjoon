#include <iostream>

using namespace std;

int answer = 0;

int main()
{
	int add = 1;
	int cnt = 0;
	int check = 9;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		answer += add;

		cnt++;
		if (cnt == check) {
			add++;
			check *= 10;
			cnt = 0;
		}
	}

	cout << answer << endl;

	return 0;
}
