#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int answer = 0;

		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;

		for (int j = 0; j < n; j++) {
			int cx, cy, r;
			cin >> cx >> cy >> r;

			if (sqrt(pow(cx - x1, 2) + pow(cy - y1, 2)) < r) {
				if (sqrt(pow(cx - x2, 2) + pow(cy - y2, 2)) >= r)
					answer++;
			}
			else {
				if (sqrt(pow(cx - x2, 2) + pow(cy - y2, 2)) < r) 
					answer++;
			}
		}
		cout << answer << endl;
	}

	return 0;
}
