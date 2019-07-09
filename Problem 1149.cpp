#include <iostream>
#include <vector>       // vector 사용
#include <algorithm>    // min 함수

#define RGB 3

using namespace std;

int main()
{
	int num;
	cin >> num;

	vector<vector<int>> house(num + 1, vector<int>(RGB, 0));
	for (int i = 1; i < num + 1; i++) {
		for (int j = 0; j < RGB; j++) {
			cin >> house[i][j];
		}
	}

	for (int i = 2; i < num + 1; i++)
		for (int j = 0; j < RGB; j++)
			house[i][j] += min(house[i - 1][(j + 1) % 3], house[i - 1][(j + 2) % 3]);

        // 마지막 house에서 R, G, B 각각의 경우들 중 최솟값을 출력한다.
	cout << min(house[num][0], min(house[num][1], house[num][2])) << endl;

	return 0;
}
