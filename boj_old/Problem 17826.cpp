#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec(0);
	for (int i = 0; i < 50; i++) {
		int num;
		cin >> num;

		vec.push_back(num);
	}

	int num;
	cin >> num;

	for (int i = 0; i < 50; i++) {
		if (vec[i] == num) {
			if (i + 1 >= 1 && i + 1 <= 5) {
				cout << "A+" << endl;
				return 0;
			}
			else if (i + 1 >= 6 && i + 1 <= 15) {
				cout << "A0" << endl;
				return 0;
			}
			else if (i + 1 >= 16 && i + 1 <= 30) {
				cout << "B+" << endl;
				return 0;
			}
			else if (i + 1 >= 31 && i + 1 <= 35) {
				cout << "B0" << endl;
				return 0;
			}
			else if (i + 1 >= 36 && i + 1 <= 45) {
				cout << "C+" << endl;
				return 0;
			}
			else if (i + 1 >= 46 && i + 1 <= 48) {
				cout << "C0" << endl;
				return 0;
			}
			else if (i + 1 >= 49 && i + 1 <= 50) {
				cout << "F" << endl;
				return 0;
			}
		}
	}
}
