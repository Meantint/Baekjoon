#include <iostream>

using namespace std;

int n, m;
bool visited[101][101] = { 0 };
char arr[101][101] = { 0 };
int answer = 0;

void dfs(int x, int y, char ch) {
	if (x >= n || y >= m || x < 0 || y < 0)
		return;
	if (visited[x][y]) {
		return;
	}
	if (arr[x][y] == ch)
		visited[x][y] = true;
	else
		return;
	if (arr[x][y] == '-') {
		dfs(x, y + 1, arr[x][y]);
	}
	if (arr[x][y] == '|') {
		dfs(x + 1, y, arr[x][y]);
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false) {
				dfs(i, j, arr[i][j]);
				answer++;
			}
		}
	}
	
	cout << answer << endl;

	return 0;
}
