#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int cnt[27] = { 0 };

int answer = 0;

int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;

	for (int i = 0; i < str1.size(); i++) {
		cnt[str1[i] - 'a' + 1]++;
	}
	for (int i = 0; i < str2.size(); i++) {
		cnt[str2[i] - 'a' + 1]--;
	}

	for (int i = 1; i < 27; i++) {
		answer += abs(cnt[i]);
	}

	cout << answer << endl;

	return 0;
}
