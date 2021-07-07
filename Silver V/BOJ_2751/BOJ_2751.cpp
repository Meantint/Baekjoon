#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for (auto& num : v) {
        cin >> num;
    }
    sort(v.begin(), v.end());
    for (auto& num : v) {
        cout << num << '\n';
    }

    return 0;
}