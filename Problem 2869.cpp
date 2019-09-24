#include <iostream>

using namespace std;

int main()
{
	int answer = 0;

	int A, B, V;
	cin >> A >> B >> V;

	answer = (V - B - 1) / (A - B) + 1;
	cout << answer << endl;

	return 0;
}
