#include <iostream>
#define MAX_N 10000
using namespace std;

int main()
{
	int arr[MAX_N];
	int n, x, i;

	cin >> n >> x;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n; i++) {
		if (arr[i] < x)
			cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
