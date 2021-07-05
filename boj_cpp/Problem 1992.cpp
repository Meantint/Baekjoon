#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int N;

void print(int N, vector<vector<char>> map) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1')	cnt++;
		}
	}
	if (cnt == N * N) {		// 1로 가득 차있을 때
		cout << "1";
		return;
	}
	else if (cnt == 0) {	// 0으로 가득 차있을 때
		cout << "0";
		return;
	}
	else {					// 0, 1로 가득차 있지 않을 때
		cout << '(';
		vector<vector<char>> map1(N / 2, vector<char>(N / 2, 0));
		vector<vector<char>> map2(N / 2, vector<char>(N / 2, 0));
		vector<vector<char>> map3(N / 2, vector<char>(N / 2, 0));
		vector<vector<char>> map4(N / 2, vector<char>(N / 2, 0));

		for (int i = 0; i < N / 2; i++) {		// 왼쪽 위
			for (int j = 0; j < N / 2; j++) {
				map1[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < N / 2; i++) {		// 오른쪽 위
			for (int j = N / 2; j < N; j++) {
				map2[i][j - N / 2] = map[i][j];
			}
		}
		for (int i = N / 2; i < N; i++) {		// 왼쪽 아래
			for (int j = 0; j < N / 2; j++) {
				map3[i - N / 2][j] = map[i][j];
			}
		}
		for (int i = N / 2; i < N; i++) {		// 오른쪽 아래
			for (int j = N / 2; j < N; j++) {
				map4[i - N / 2][j - N / 2] = map[i][j];
			}
		}
		print(N / 2, map1);
		print(N / 2, map2);
		print(N / 2, map3);
		print(N / 2, map4);
		cout << ')';
	}
}

int main()
{
	cin >> N;
	vector<vector<char>> map(N, vector<char>(N, 0));

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			cin >> map[i][j];
		}
	}

	print(N, map);

	return 0;
}
