#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> answer;

int main()
{
    cin >> n >> m;

    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    // empty로 인한 문제를 없애기 위해
    answer.push_back(vector<int>(m, -1));
    do {
        vector<int> tmp1 = answer.back();
        vector<int> tmp2;
        bool isSame = true;
        for (int i = 0; i < m; ++i) {
            tmp2.push_back(num[i]);
        }
        if (tmp1 != tmp2) {
            answer.push_back(tmp2);
        }
    } while (next_permutation(num.begin(), num.end()));

    int size = answer.size();
    for (int i = 1; i < size; ++i) {
        for (auto& elem : answer[i]) {
            cout << elem << ' ';
        }
        cout << '\n';
    }

    return 0;
}