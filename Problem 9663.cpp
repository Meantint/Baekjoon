#include <iostream>
#include <cmath>

using namespace std;

int N;
int cnt = 0;
int* cols;

// 유망한지 검사
bool isPromising(int level){
	for (int i = 1; i < level; ++i) {
		if (cols[i] == cols[level]) 				// 같은 열에 놓여있다면
			return false;
		else if ((level - i) == abs(cols[level] - cols[i]))	// 같은 대각선상에 있다면
			return false;
	}
	return true;
}

// 백트래킹 -> dfs + 조건문의 조합으로 봐도 됨
void dfs(int level) {
	if (!isPromising(level))	
		return;
	else if (level == N) {	// level이 끝에 도달하였다면
		cnt += 1;
		return;
	}
	else { 			// 유망함과 동시에 끝부분에 도달하지 않았다면
		for (int col = 1; col <= N; ++col) {
			cols[level + 1] = col;
			dfs(level + 1);
		}
	}
}

void solve() {
	cin >> N;
	cols = new int[N + 1];
	for (int i = 0; i < N + 1; ++i) {
		cols[i] = 0;
	}
	dfs(0);
	cout << cnt << "\n";

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();

	return 0;
}
