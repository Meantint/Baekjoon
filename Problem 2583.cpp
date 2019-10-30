#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;

int map[101][101] = { 0 };
bool visited[101][101] = { 0 };
vector<int> answer(0);

int dfs(int i, int j, int cnt) {
	if (i <= 0 || j <= 0 || i > N || j > M) {
		return cnt;
	}

	if (visited[i][j])
		return cnt;
	visited[i][j] = true;
	if (map[i][j] == 0) {
		cnt++;
		cnt = dfs(i, j + 1, cnt);
		cnt = dfs(i, j - 1, cnt);
		cnt = dfs(i + 1, j, cnt);
		cnt = dfs(i - 1, j, cnt);
	}
	return cnt;
}

int main()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1 + 1; x <= x2; x++) {
			for (int y = y1 + 1; y <= y2; y++) {
				map[x][y] = 1;
				visited[x][y] = true;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j]) {
				answer.push_back(dfs(i, j, 0));
			}
		}
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}

	return 0;
}
