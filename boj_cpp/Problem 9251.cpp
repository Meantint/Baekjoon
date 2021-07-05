#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	vector<vector<int>> map(str1.size() + 1, vector<int>(str2.size() + 1, 0));

	for (int i = 1; i < map.size(); i++) {
		for (int j = 1; j < map[0].size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else {
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
			}
		}
	}

	cout << map[str1.size()][str2.size()] << endl;

	return 0;
}
