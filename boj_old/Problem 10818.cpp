#include <iostream>

#define MAX 1000000

using namespace std;

int main()
{
	int n, i;
	int min, max;
	int arr[MAX];

	cin >> n;
	cin >> arr[0];
	max = arr[0];
	min = arr[0];
	for (i = 1; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] < min)
			min = arr[i];
		else if (arr[i] > max)
			max = arr[i];
	}
	cout << min << " " << max << endl;
}
