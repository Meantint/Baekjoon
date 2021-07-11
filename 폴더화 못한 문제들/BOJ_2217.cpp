#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<int>());

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer = max(answer, vec[i] * (i + 1));
    }
    cout << answer << '\n';

    return 0;
}