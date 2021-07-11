#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec(4);
    for (int i = 0; i < 4; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cout << abs(vec[0] + vec[3] - vec[1] - vec[2]) << '\n';

    return 0;
}