#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

int t, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> n;
        vector<PII> vec;
        for (int i = 0; i < n; ++i) {
            int num1, num2;
            cin >> num1 >> num2;
            vec.push_back(make_pair(num1, num2));
        }
        sort(vec.begin(), vec.end());

        int answer = 0;
        for (int i = vec.size() - 1; i >= 0; --i) {
            bool isBool = true;
            for (int j = i - 1; j >= 0; --j) {
                if (vec[i].second >= vec[j].second) {
                    isBool = false;
                    break;
                }
            }
            if (isBool) {
                ++answer;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}