#include <iostream>

using namespace std;

bool computer[101] = { 0 };
int answer = 0;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		if (computer[num]) {
			answer++;
		}
		else {
			computer[num] = true;
		}
	}

	cout << answer << endl;

	return 0;
}
