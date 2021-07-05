#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;

bool comp(const pair<int, string>& p1, const pair<int, string>& p2) {
	/*if (p1.first == p2.first) {
		return false;
	}*/
	return p1.first < p2.first;
}

void solve() {
	cin >> N;
	vector<pair<int, string>> v;
	for (int i = 0; i < N; ++i) {
		int num;
		string str;
		cin >> num >> str;
		v.push_back(pair<int, string>(num, str));
	}
	// stable_sort를 사용하는 이유는 비교하는 값이 똑같을 때 원소의 순서를 그대로 유지하기 위해서이다.
	// 일반 sort를 사용하면 원소의 순서가 유지되지 않을 수도 있음
	stable_sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; ++i) {
		cout << v[i].first << " " << v[i].second << "\n";
		// printf("%d %s\n", v[i].first, v[i].second.c_str());
	}

	return;
}

int main()
{
	solve();

	return 0;
}
