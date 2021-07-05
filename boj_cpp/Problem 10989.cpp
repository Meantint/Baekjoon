#include <iostream>

using namespace std;

int arr[10001] = { 0 };

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		arr[num]++;
	}

	for (int i = 1; i < 10001; i++) {
		int k = arr[i];
		for (int j = 0; j < k; j++)
			printf("%d \n", i);
	}

	return 0;
}
