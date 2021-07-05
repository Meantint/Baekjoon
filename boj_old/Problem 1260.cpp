#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int matrix[1001][1001] = { 0 };
int visit[1001] = { 0 };
int N, M, V;

void dfs(int v) {
	cout << v << ' ';
	visit[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1 || matrix[v][i] == 0)
			continue;
		dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visit[v] = 0;
	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0 || matrix[v][i] == 0)
				continue;
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main()
{
	int x, y;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		matrix[x][y] = matrix[y][x] = 1;
	}
	dfs(V);
	cout << '\n';
	bfs(V);

	return 0;
}
