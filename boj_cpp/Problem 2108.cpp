#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

bool comp(const pair<int, int>& comp1, const pair<int, int>& comp2) {
	if (comp1.second == comp2.second) { 		// 개수가 똑같을 때는 값 작은 것이 앞으로
		return comp1.first < comp2.first;	// 오름차순
	}
	return comp1.second > comp2.second;		// 내림차순
}

void solve() {
	vector<int> v;
	int key;
	double sum = 0;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> key;
		sum += key;
		v.push_back(key);
	}

	// 산술 평균
#if 0
	sum /= N;
	cout << (int)floor(sum + 0.5) << endl;
#endif
	cout << (int)floor((sum / N) + 0.5) << endl;

	sort(v.begin(), v.end());
	// 중앙값
	cout << v[N / 2] << endl; // 문제에서 N은 홀수이기 떄문에

	// 최빈값
	vector<pair<int, int>> st;
	for (int i = 0; i < v.size(); ++i) {
		if (st.empty()) {
			st.push_back(pair<int, int>(v[i], 1));
			continue;
		}

		if (st.back().first == v[i]) {
			pair<int, int> tmp = st.back();
			tmp.second++;
			st.pop_back();
			st.push_back(tmp);
		}
		else {
			st.push_back(pair<int, int>(v[i], 1));
		}
	}
	sort(st.begin(), st.end(), comp);
	if (st[0].second == st[1].second)
		cout << st[1].first << endl;
	else
		cout << st[0].first << endl;

	// 범위
	cout << v.back() - v.front() << endl;
}

int main()
{
	solve();

	return 0;
}
