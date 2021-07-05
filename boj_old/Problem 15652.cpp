#include <iostream>

using namespace std;

int N, M;
int lists[9];

void dfs(int lvl) {
	if (lvl == M) {
		for (int i = 1; i <= M; ++i) {
			cout << lists[i] << ' ';
		}
		cout << "\n";

		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (lists[lvl] > i) continue;

		lists[lvl + 1] = i;
		dfs(lvl + 1);
	}
}

void solve() {
	cin >> N >> M;
	
	dfs(0);

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}
