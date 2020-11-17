#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

long long answer = 0;
vector<string> v(3);
map<string, int> m = {
    {"black", 0},
    {"brown", 1},
    {"red", 2},
    {"orange", 3},
    {"yellow", 4},
    {"green", 5},
    {"blue", 6},
    {"violet", 7},
    {"grey", 8},
    {"white", 9},
};

int main()
{
    for (int i = 0; i < 3; ++i) {
        cin >> v[i];
    }
    answer = m[v[0]] * 10 + m[v[1]];
    answer *= (long long)pow(10, m[v[2]]);

    cout << answer << '\n';

    return 0;
}