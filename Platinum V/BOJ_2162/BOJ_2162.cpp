#include <iostream>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define ff first
#define ss second

using namespace std;

int n;
vector<int> parent;
vector<pair<pii, pii>> pos_info;

ll ccw(pii p0, pii p1, pii p2)
{
    return 1LL * (p1.ff - p0.ff) * (p2.ss - p0.ss) - 1LL * (p2.ff - p0.ff) * (p1.ss - p0.ss);
}

void input()
{
    cin >> n;

    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    pos_info.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> pos_info[i].ff.ff >> pos_info[i].ff.ss >> pos_info[i].ss.ff >> pos_info[i].ss.ss;
    }
}

int find(int n)
{
    if (parent[n] == n) {
        return n;
    }
    else {
        return parent[n] = find(parent[n]);
    }
}

void merge(int n1, int n2)
{
    int p1 = find(n1);
    int p2 = find(n2);

    if (p1 < p2) {
        parent[p2] = p1;
    }
    else {
        parent[p1] = p2;
    }
}

int main()
{
    input();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (find(i) == find(j)) {
                continue;
            }

            ll v1 = ccw(pos_info[i].ff, pos_info[i].ss, pos_info[j].ff) * ccw(pos_info[i].ff, pos_info[i].ss, pos_info[j].ss);
            ll v2 = ccw(pos_info[j].ff, pos_info[j].ss, pos_info[i].ff) * ccw(pos_info[j].ff, pos_info[j].ss, pos_info[i].ss);

            if (v1 == 0 && v2 == 0) {
                if (pos_info[i].ff > pos_info[i].ss) {
                    pii temp = pos_info[i].ff;
                    pos_info[i].ff = pos_info[i].ss;
                    pos_info[i].ss = temp;
                }
                if (pos_info[j].ff > pos_info[j].ss) {
                    pii temp = pos_info[j].ff;
                    pos_info[j].ff = pos_info[j].ss;
                    pos_info[j].ss = temp;
                }

                if (pos_info[i].ff <= pos_info[j].ss && pos_info[j].ff <= pos_info[i].ss) {
                    merge(i, j);
                }
            }
            else if (v1 <= 0 && v2 <= 0) {
                merge(i, j);
            }
        }
    }

    vector<int> answer(n, 0);
    for (int i = 0; i < n; ++i) {
        ++answer[find(i)];
    }
    int group = 0;
    int max_group = 0;
    for (int i = 0; i < n; ++i) {
        if (answer[i] != 0) {
            ++group;
            if (max_group < answer[i]) {
                max_group = answer[i];
            }
        }
    }

    cout << group << '\n'
         << max_group << '\n';

    return 0;
}