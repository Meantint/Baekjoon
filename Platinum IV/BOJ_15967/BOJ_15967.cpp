#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, q1, q2;
vector<int> cost, lazy;
vector<ll> seg;

void propagate(int node, int left, int right)
{
    if (lazy[node] != 0) {
        // not leaf node
        if (left != right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        seg[node] += (ll)lazy[node] * (ll)(right - left + 1);
        lazy[node] = 0;
    }
}

ll init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = cost[left];
    }

    int mid = ((left + right) >> 1);
    ll left_info = init(node * 2, left, mid);
    ll right_info = init(node * 2 + 1, mid + 1, right);
    return seg[node] = left_info + right_info;
}

void update(int node, int left, int right, int start, int end, int value)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return;
    }
    if (start <= left && right <= end) {
        lazy[node] += (ll)value;
        propagate(node, left, right);

        return;
    }

    int mid = ((left + right) >> 1);
    update(node * 2, left, mid, start, end, value);
    update(node * 2 + 1, mid + 1, right, start, end, value);
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

    cin >> n >> q1 >> q2;
    cost.resize(n);
    int seg_size = 1;
    while (seg_size < n) {
        seg_size *= 2;
    }
    seg.resize(seg_size * 2);
    lazy.resize(seg_size * 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < q1 + q2; ++i) {
        int case_num;
        cin >> case_num;

        // Query
        if (case_num == 1) {
            int start, end;
            cin >> start >> end;

            cout << query(1, 0, n - 1, start - 1, end - 1) << '\n';
        }
        // Update
        else {
            int start, end, value;
            cin >> start >> end >> value;

            update(1, 0, n - 1, start - 1, end - 1, value);
        }
    }

    return 0;
}