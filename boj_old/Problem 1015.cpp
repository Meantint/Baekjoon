#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main()
{
	cin >> N;

	vector<pair<int, int>> A(0);
	vector<pair<int, int>> B(0);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		A.push_back(make_pair(num, i));
		B.push_back(make_pair(0, i));
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		B[i].first = A[i].second;
	}
	
	sort(B.begin(), B.end());
	for (int i = 0; i < N; i++) {
		cout << B[i].second << " ";
	}

	return 0;
}
