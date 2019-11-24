#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int x, y;
		cin >> x >> y;

		int dist = y - x;
		int alpha, beta;
		alpha = (int)sqrt(dist);
		beta = pow(alpha, 2);

		if (dist == beta)
			cout << alpha * 2 - 1 << endl;
		else if (dist <= alpha + beta)
			cout << alpha * 2 << endl;
		else
			cout << alpha * 2 + 1 << endl;
	}

	return 0;
}
