#include <iostream>

using namespace std;

int N, M;
int lists[9];
int cnt_Arr[9];
bool check[9];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < cnt_Arr[i]; ++j) {
				cout << lists[i] << " ";
			}
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i) {
		lists[cnt] = i;
		cnt_Arr[cnt]++;
		dfs(cnt + 1);
		cnt_Arr[cnt]--;
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
