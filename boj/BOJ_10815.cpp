#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> answer;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int n;
        cin >> n;
        int find = lower_bound(v.begin(), v.end(), n) - v.begin();
        if (v[find] == n) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }
    for (int i = 0; i < M; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}