#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int answer = 0;

void dfs(int i, int j) {
	if (N == 0) 
		return;
	N -= 1;
	int k = pow(2, N);
	if (r < i + k) {
		if (c < j + k) {			// 1 구역
			dfs(i, j);
		}
		else {					// 2 구역
			answer += k * k;
			dfs(i, j + k);
		}
	}
	else {
		if (c < j + k) {			// 3 구역
			answer += 2 * k * k;
			dfs(i + k, j);
		}
		else {					// 4 구역
			answer += 3 * k * k;
			dfs(i + k, j + k);
		}
	}
}

int main()
{
	cin >> N >> r >> c;

	dfs(0, 0);
	cout << answer << endl;
}
