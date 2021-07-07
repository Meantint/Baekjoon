#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, mx_val = -1;
int answer = 0;
vector<int> v;

int main()
{
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        answer += v[i];
    }
    for (auto &val : v) {
        mx_val = max(mx_val, val);
    }
    cout << ((double)(answer * 100) / (double)n) / (double)mx_val << '\n';

    return 0;
}