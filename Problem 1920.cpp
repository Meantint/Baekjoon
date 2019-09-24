#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// cout 쓰면 안 되는데 printf, scanf 쓰면 됨. 시간 차이 많이 나는 듯
int main()
{
	int n, m;
	cin >> n;

	vector<int> arr1(n, 0);
	for (int i = 0; i < arr1.size(); i++) {
		cin >> arr1[i];
	}
	cin >> m;
	vector<int> arr2(m, 0);
	for (int i = 0; i < arr2.size(); i++) {
		cin >> arr2[i];
	}

	sort(arr1.begin(), arr1.end());

	int left, right, mid;
	for (int i = 0; i < arr2.size(); i++) {
		int findN = arr2[i];
		left = 0;
		right = arr1.size() - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr1[mid] > findN) {
				right = mid - 1;
			}
			else if (arr1[mid] < findN) {
				left = mid + 1;
			}
			else {
				printf("1 \n");
				break;
			}
		}
		if (left > right) {
			printf("0\n");
		}
	}

	return 0;
}
