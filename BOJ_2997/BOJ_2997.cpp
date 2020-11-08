#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int answer;
vector<int> v(3);

int main()
{
    for (int i = 0; i < 3; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (v[0] - v[1] == v[1] - v[2]) {
        answer = v[2] + v[1] - v[0];
    }
    else if (v[1] - v[0] > v[2] - v[1]) {
        answer = v[0] + v[2] - v[1];
    }
    else {
        answer = v[2] - v[1] + v[0];
    }
    cout << answer << '\n';

    return 0;
}