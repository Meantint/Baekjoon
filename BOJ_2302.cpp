#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> m;
        /*
	if(n == m){
		cout << '1' << '\n';
		return 0;
	}
	*/
        int vip[m];
        for (int i = 0; i < m; ++i) {
                cin >> vip[i];
        }

        vector<vector<int>> area(0);
        int idx = 0;
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
                if (i != vip[idx] - 1) {
                        tmp.push_back(i);
                }
                else {
                        ++idx;
                        if (tmp.empty()) {
                                continue;
                        }
                        area.push_back(tmp);
                        tmp.clear();
                }
        }
        if (!tmp.empty())
                area.push_back(tmp);
        /*
	cout << "area.size() = " << area.size() << '\n';

	for(int i = 0; i < area.size(); ++i){
		for(int j = 0; j < area[i].size(); ++j){
			cout << area[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

        int answer = 1;
        int row = area.size();
        for (int i = 0; i < row; ++i) {
                int col = area[i].size();
                if (col <= 2) {
                        answer *= col;
                        continue;
                }
                area[i][0] = 1;
                area[i][1] = 2;
                for (int j = 2; j < col; ++j) {
                        area[i][j] = area[i][j - 1] + area[i][j - 2];
                }
                answer *= area[i].back();
        }
        cout << answer << '\n';

        return 0;
}
