#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;

	if (h == 0 && 45 > m) {
		cout << 23 << " " << 15 + m << endl;
	}
	else if (45 > m) {
		cout << h - 1 << " " << 15 + m << endl;
	}
	else {
		cout << h << " " << m - 45 << endl;
	}
}
