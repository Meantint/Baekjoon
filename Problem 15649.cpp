#include <iostream>

using namespace std;

int N, M;
int lists[9];
bool check[9];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; ++i) {
			cout << lists[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (!check[i]) {
			check[i] = true;
			lists[cnt] = i;
			dfs(cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	dfs(0);

	return 0;
}
