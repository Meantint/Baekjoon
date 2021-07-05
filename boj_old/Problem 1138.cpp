#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[20] = { 0 };
int real[20] = { 0 };

int main()
{
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	real[1] = n;
	for (int i = n - 1; i > 0; i--) {
		int idx = arr[i];
		
		for (int j = n; j > idx; j--) {
			real[j + 1] = real[j];
		}
		real[idx + 1] = i;
	}

	for (int i = 1; i <= n; i++) {
		cout << real[i] << ' ';
	}

	return 0;
}
