// Brute Force를 활용하면 풀 수 있음.
// 문자열 "666"을 이용하여 풀려고 하였으나 실패했음.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int count = 1;
	int baseNum = 666;

	while (1) {
		if (n == count) {
			break;
		}

		baseNum++;

		int copyNum = baseNum;
		int flag = 0;
		while (copyNum) {
			if (copyNum % 10 == 6) {
				flag++;
			}
			else flag = 0;
			
			if (flag == 3) {
				count++;
				break;
			}
			copyNum /= 10;
		}
	}

	cout << baseNum << endl;

	return 0;
}
