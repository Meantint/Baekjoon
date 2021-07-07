#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m, cnt;
int answer = 0;

vector<int> info(5);
vector<vector<int>> info_all;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve()
{
	for (int count = 0; count < cnt; ++count)
	{
		vector<vector<vector<tuple<int, int, int>>>> board(n, vector<vector<tuple<int, int, int>>>(n, vector<tuple<int, int, int>>(0)));

		int info_size = info_all.size();
		// cout << info_size << '\n';
		for (int i = 0; i < info_size; ++i)
		{
			board[(info_all[i][0] + info_all[i][3] * (dx[info_all[i][4]]) + n * 1000) % n][(info_all[i][1] + info_all[i][3] * (dy[info_all[i][4]]) + n * 1000) % n].push_back(make_tuple(info_all[i][2], info_all[i][3], info_all[i][4]));
		}
		/*
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(board[i][j].size() == 0){
					cout << 0 << ' ';
				}
				else{
					cout << get<0>(board[i][j][0]) << ' ';
				}
			}
			cout << '\n';
		}
		*/

		info_all.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				// cout << "count, i, j : " << count << ", " << i << ", " << j << '\n';
				int size = board[i][j].size();
				if (size == 0)
				{
					continue;
				}
				int is_same = 1;
				int is_odd = (get<2>(board[i][j][0])) % 2;
				int weight_all = 0;
				int speed_all = 0;
				for (int k = 0; k < size; ++k)
				{
					if (is_same == 1)
					{
						if (get<2>(board[i][j][k]) % 2 != is_odd)
						{
							is_same = 0;
						}
					}
					weight_all += get<0>(board[i][j][k]);
					speed_all += get<1>(board[i][j][k]);
				}
				// cout << "wow\n";

				// 2개 이상이라면 4개로 분할
				if (size > 1)
				{
					if (is_same == 1 && weight_all >= 5)
					{
						info_all.push_back({i, j, weight_all / 5, speed_all / size, 0});
						info_all.push_back({i, j, weight_all / 5, speed_all / size, 2});
						info_all.push_back({i, j, weight_all / 5, speed_all / size, 4});
						info_all.push_back({i, j, weight_all / 5, speed_all / size, 6});
					}
					else if (is_same == 0 && weight_all >= 5)
					{
						info_all.push_back({i, j, weight_all / 5, speed_all / size, 1});
						info_all.push_back({i, j, weight_all / 5, speed_all / size, 3});
						info_all.push_back({i, j, weight_all / 5, speed_all / size, 5});
						info_all.push_back({i, j, weight_all / 5, speed_all / size, 7});
					}
				}
				// 1개
				else
				{
					info_all.push_back({i, j, weight_all, speed_all, get<2>(board[i][j][0])});
				}
			}
		}
	}

	int info_size = info_all.size();
	for (int i = 0; i < info_size; ++i)
	{
		answer += info_all[i][2];
	}
}

int main()
{
	cin >> n >> m >> cnt;
	for (int i = 0; i < m; ++i)
	{
		cin >> info[0] >> info[1] >> info[2] >> info[3] >> info[4];
		info[0] -= 1;
		info[1] -= 1;
		info_all.push_back(info);
	}

	solve();

	cout << answer << '\n';

	return 0;
}
