#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

using namespace std;

int R;

void solve() {
	cin >> R;
	cout << fixed;
	cout.precision(6);

	cout << R * R * PI << endl;
	cout << R * R * 2 << endl;

	return;
}

int main()
{
	solve();

	return 0;
}
