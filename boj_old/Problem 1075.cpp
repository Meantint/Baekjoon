#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N, F;
	cin >> N >> F;

	int k = 0;
	N = N - (N % 100);
	while (1) {
		if ((N + k) % F == 0) {
			break;
		}
		else {
			k++;
		}
	}

	if (k < 10) {
		cout << "0" << k << endl;
	}
	else {
		cout << k << endl;
	}

	return 0;
}
