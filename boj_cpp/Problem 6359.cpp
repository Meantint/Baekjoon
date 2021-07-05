#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		// floor : 가우스 함수
		cout << floor(sqrt(num)) << endl;
	}

	return 0;
}
