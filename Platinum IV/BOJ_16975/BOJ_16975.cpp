#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, m;
int tree_size = 1;
vector<int> value;
vector<ll> seg, lazy;

void propagate(int node, int left, int right)
{
    if (lazy[node] != 0) {
        if (left != right) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        else {
            seg[node] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void init(int node, int left, int right)
{
    if (left == right) {
        seg[node] = value[left];

        return;
    }

    int mid = ((left + right) >> 1);
    init(node * 2, left, mid);
    init(node * 2 + 1, mid + 1, right);

    return;
}

void update(int node, int left, int right, int start, int end, ll v)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return;
    }
    if (start <= left && right <= end) {
        lazy[node] += v;
        propagate(node, left, right);

        return;
    }

    int mid = ((left + right) >> 1);
    update(node * 2, left, mid, start, end, v);
    update(node * 2 + 1, mid + 1, right, start, end, v);

    return;
}

ll query(int node, int left, int right, int target)
{
    propagate(node, left, right);

    if (target < left || right < target) {
        return -1;
    }
    if (left == right && left == target) {
        return seg[node];
    }

    int mid = ((left + right) >> 1);
    ll left_info = query(node * 2, left, mid, target);
    if (left_info != -1) {
        return left_info;
    }
    return query(node * 2 + 1, mid + 1, right, target);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    value.resize(n);
    while (tree_size < n) {
        tree_size *= 2;
    }
    seg.resize(tree_size * 2, 0);
    lazy.resize(tree_size * 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    init(1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int case_num;
        cin >> case_num;

        if (case_num == 1) {
            int start, end, v;
            cin >> start >> end >> v;

            update(1, 0, n - 1, start - 1, end - 1, v);
        }
        else {
            int index;
            cin >> index;

            cout << query(1, 0, n - 1, index - 1) << '\n';
        }
    }

    return 0;
}