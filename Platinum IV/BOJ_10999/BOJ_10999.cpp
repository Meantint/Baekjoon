#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, m, k;
vector<int> value, lazy;
vector<ll> seg;

void propagate(int node, int left, int right)
{
    if (lazy[node] != 0) {
        if (left != right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] += (ll)(right - left + 1) * (ll)lazy[node];
        lazy[node] = 0;
    }
}

ll init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = value[left];
    }

    int mid = ((left + right) >> 1);
    return seg[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int start, int end, int change)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return;
    }
    if (start <= left && right <= end) {
        lazy[node] += change;
        propagate(node, left, right);

        return;
    }

    int mid = ((left + right) >> 1);
    update(node * 2, left, mid, start, end, change);
    update(node * 2 + 1, mid + 1, right, start, end, change);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];

    return;
}

ll query(int node, int left, int right, int start, int end)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return 0;
    }
    if (start <= left && right <= end) {
        return seg[node];
    }

    int mid = ((left + right) >> 1);
    return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    value.resize(n);

    int seg_size = 1;
    while (seg_size < n) {
        seg_size *= 2;
    }
    seg.resize(seg_size * 2);
    lazy.resize(seg_size * 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < m + k; ++i) {
        int case_num;
        cin >> case_num;

        // Update
        if (case_num == 1) {
            int start, end, change;
            cin >> start >> end >> change;

            update(1, 0, n - 1, start - 1, end - 1, change);
        }
        // Query
        else {
            int start, end;
            cin >> start >> end;

            cout << query(1, 0, n - 1, start - 1, end - 1) << '\n';
        }
    }

    return 0;
}