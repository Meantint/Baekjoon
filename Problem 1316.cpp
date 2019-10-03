#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int answer = 0;

	int n;
	cin >> n;

	vector<string> str(n);
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < n; i++) {
		bool cntArr[27] = { 0 };
		for (int j = 0; j < str[i].size(); j++) {
			if (cntArr[str[i][j] - 'a' + 1] == true) {
				break;
			}
			cntArr[str[i][j] - 'a' + 1] = true;
			while (j + 1 < str[i].size() && str[i][j] == str[i][j + 1]) {
				j++;
			}
			if (j == str[i].size() - 1) {	// 위치 매우 중요!
				answer++;		// 처음에 25번째 줄 코드의 앞에 놔두었는데
				break;			// 하나의 알파벳만 여러 개 나오는 케이스를 제대로 처리하지 못했음.
			}
		}
	}

	cout << answer << endl;

	return 0;
}
