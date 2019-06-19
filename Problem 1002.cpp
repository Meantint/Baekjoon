#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	int x1, x2, y1, y2;
	int r1, r2;

	cin >> T;
	for (int i = 0; i < T; i++) {	// Test Case 만큼 돌아라
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int k = pow(x2 - x1, 2) + pow(y2 - y1, 2);	// (x1, y1)과 (x2, y2) 사이의 거리 k

		if (x1 == x2 && y1 == y2 && r1 == r2) {		// x, y 좌표가 같고 원의 반지름 길이도 같을 때
			cout << "-1" << endl;
			continue;
		}
		else if (x1 == x2 && y1 == y2 && r1 != r2) {
			cout << "0" << endl;
			continue;
		}
		else if (k == pow(r1 + r2, 2)) {			// 원이 한 점에서 만나는 경우
			cout << "1" << endl;
			continue;
		}
		else if (k > pow(r1 + r2, 2)) {				// 원이 서로 만나지 못하는 경우
			cout << "0" << endl;
			continue;
		}
		else if (k < pow(r1 + r2, 2)) {				// 원이 두 점에서 만나는 경우 (이 경우는 원안에 원이 들어가있는 형태일 수가 있으므로
									// 따로 조건문을 더 실행한다.
			if (k < pow(r1 - r2, 2)) {			// 큰 반지름에서 작은 반지름으로 뺀 값이 k보다 클 때
				cout << "0" << endl;			// 어느 점에서도 만나지 않는다.
				continue;
			}
			else if (k > pow(r1 - r2, 2)) {			// 큰 반지름에서 작은 반지름으로 뺀 값이 k보다 작을 때
				cout << "2" << endl;			// 두 점에서 만난다.
				continue;
			}
			else if (k == pow(r1 - r2, 2)) {		// 큰 반지름에서 작은 반지름으로 뺀 값이 k와 같을 때
				cout << "1" << endl;			// 한 점에서 만난다.
				continue;
			}
		}
	}

	return 0;
}
