#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

int main()
{
        int N;
        cin >> N;

        vector<PII> vec;
        for (int i = 0; i < N; ++i) {
                int height;
                cin >> height;

                vec.push_back(make_pair(i, height));
        }

        int answer = 0;
        int size = vec.size();
        for (int i = 0; i < size; ++i) {
                int cnt = 0;
                double prev = -2000000000;
                // 왼쪽으로 가면서 만나는 건물들을 비교
                for (int j = i - 1; j >= 0; --j) {
                        double val = (double)(vec[j].second - vec[i].second) / (double)(vec[i].first - vec[j].first);
                        if (val > prev) {
                                ++cnt;
                                prev = val;
                        }
                }
                prev = -2000000000;
                // 오른쪽으로 가면서 만나는 건물들을 비교
                for (int j = i + 1; j < size; ++j) {
                        double val = (double)(vec[j].second - vec[i].second) / (double)(vec[j].first - vec[i].first);
                        if (val > prev) {
                                ++cnt;
                                prev = val;
                        }
                }
                answer = max(answer, cnt);
        }
        cout << answer << '\n';

        return 0;
}