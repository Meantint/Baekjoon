#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int firstAlphabet[27] = { 0 };
int cnt = 0;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		firstAlphabet[str[0] - 'a' + 1]++;
	}

	for (int i = 1; i < 27; i++) {
		if (firstAlphabet[i] >= 5) {
			printf("%c", i - 1 + 'a');
		}
		else {
			cnt++;
		}
	}

	if (cnt == 26) {
		cout << "PREDAJA" << endl;
	}

	return 0;
}
