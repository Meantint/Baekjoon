#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[51][51] = { 0 };
int visited[51][51] = { 0 };

void dfs(int i, int j) {
	if (i <= 0 || j <= 0 || i > m || j > n)	return;
	if (visited[i][j])	return;

	visited[i][j] = true;
	if (map[i][j] == 0)	return;
	map[i][j] = 0;

	dfs(i, j + 1);
	dfs(i, j - 1);

	dfs(i + 1, j);
	dfs(i - 1, j);

	dfs(i + 1, j + 1);
	dfs(i + 1, j - 1);

	dfs(i - 1, j + 1);
	dfs(i - 1, j - 1);
}


int main()
{
	while (1) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				visited[i][j] = false;
			}
		}

		int cnt = 0;

		cin >> n >> m;
		if (n == 0 && m == 0)	break;

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
