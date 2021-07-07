#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> str;

bool comp(const string &s1, const string &s2)
{
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

int main()
{
    cin >> n;
    str.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    sort(str.begin(), str.end(), comp);
    str.erase(unique(str.begin(), str.end()), str.end());

    for (auto &s : str) {
        cout << s << '\n';
    }

    return 0;
}