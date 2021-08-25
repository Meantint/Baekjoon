#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int n;
vector<tuple<string, int, int, int>> info(0);

bool comp(tuple<string, int, int, int>& t1, tuple<string, int, int, int>& t2)
{
    if (get<1>(t1) == get<1>(t2)) {
        if (get<2>(t1) == get<2>(t2)) {
            if (get<3>(t1) == get<3>(t2)) {
                return get<0>(t1) < get<0>(t2);
            }
            return get<3>(t1) > get<3>(t2);
        }
        return get<2>(t1) < get<2>(t2);
    }
    return get<1>(t1) > get<1>(t2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        int s1, s2, s3;
        cin >> str >> s1 >> s2 >> s3;

        info.push_back(make_tuple(str, s1, s2, s3));
    }

    sort(info.begin(), info.end(), comp);

    for (auto a : info) {
        cout << get<0>(a) << '\n';
    }

    return 0;
}