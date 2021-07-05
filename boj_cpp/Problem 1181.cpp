#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
string str[20100];

bool comp(const string& str1, const string& str2) {
	if (str1.size() == str2.size()) {
		return str1 < str2;
	}
	return str1.size() < str2.size();
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {	
		/*string word;
		cin >> word;
		str.push_back(word);*/
		cin >> str[i];
	}

	sort(str, str + N, comp);
	string previous;
	for (int i = 0; i < N; ++i) {
		if (str[i] == previous) continue;
		cout << str[i] << endl;
		previous = str[i];
	}

	return;
}

int main()
{
	solve();

	return 0;
}
