#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<int> v(N + 1);
    vector<int> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }
    prefixSum[1] = v[0];
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }
    while (M--) {
        int st, ed;
        cin >> st >> ed;
        cout << prefixSum[ed] - prefixSum[st - 1] << '\n';
    }

    return 0;
}