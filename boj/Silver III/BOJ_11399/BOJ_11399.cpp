#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; ++i) {
        v[i] += v[i - 1];
    }
    for (auto& num : v) {
        answer += num;
    }
    cout << answer << '\n';

    return 0;
}