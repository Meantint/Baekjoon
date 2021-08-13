#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#define ll long long

using namespace std;

stack<pair<int, int>> st;

int n;
pair<int, int> p0;
vector<pair<int, int>> pos_info;

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    ll vi = p1.first - p0.first;
    ll vj = p1.second - p0.second;
    ll wi = p2.first - p0.first;
    ll wj = p2.second - p0.second;

    ll temp = vi * wj - vj * wi;
    if (temp == 0) {
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    }
    else if (temp > 0) {
        return true;
    }
    else {
        return false;
    }
}

int ccw(pair<int, int> p0, pair<int, int> p1, pair<int, int> p2)
{
    ll temp = (ll)(p1.first - p0.first) * (ll)(p2.second - p0.second) - (ll)(p2.first - p0.first) * (ll)(p1.second - p0.second);

    // 반시계
    if (temp > 0) {
        return 1;
    }
    else if (temp == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

int main()
{
    cin >> n;
    pos_info.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos_info[i].first >> pos_info[i].second;
    }
    sort(pos_info.begin(), pos_info.end());
    p0 = pos_info[0];

    sort(pos_info.begin() + 1, pos_info.end(), comp);

    st.push(pos_info[0]);
    st.push(pos_info[1]);

    pair<int, int> p1, p2, p3;
    for (int i = 2; i < n; ++i) {
        while (st.size() >= 2) {
            p2 = st.top();
            st.pop();
            p1 = st.top();
            p3 = pos_info[i];

            int temp = ccw(p1, p2, p3);
            if (temp > 0) {
                st.push(p2);
                break;
            }
        }
        st.push(p3);
    }

    cout << st.size() << '\n';

    return 0;
}