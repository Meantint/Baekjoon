#include <iostream>
#include <vector>

using namespace std;

int n, m;
int tree_size = 1;
vector<int> value;
vector<int> seg, lazy;

int dc(int v, int range)
{
    if (range == 1) {
        return v;
    }
    else if (range % 2 == 0) {
        int temp = dc(v, range / 2);
        return (temp ^ temp);
    }
    else {
        int new_range = (range - 1) / 2;
        int temp = dc(v, new_range);
        return (temp ^ temp ^ v);
    }
}

void propagate(int node, int left, int right)
{
    if (lazy[node] != 0) {
        if (left != right) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        int range = right - left + 1;
        seg[node] ^= dc(lazy[node], range);
        lazy[node] = 0;
    }
}

int init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = value[left];
    }

    int mid = ((left + right) >> 1);
    return seg[node] = (init(node * 2, left, mid) ^ init(node * 2 + 1, mid + 1, right));
}

void update(int node, int left, int right, int start, int end, int v)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return;
    }
    if (start <= left && right <= end) {
        lazy[node] ^= v;
        propagate(node, left, right);

        return;
    }

    int mid = ((left + right) >> 1);
    update(node * 2, left, mid, start, end, v);
    update(node * 2 + 1, mid + 1, right, start, end, v);
    seg[node] = (seg[node * 2 + 1] ^ seg[node * 2]);

    return;
}

int query(int node, int left, int right, int start, int end)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return 0;
    }
    if (start <= left && right <= end) {
        return seg[node];
    }

    int mid = ((left + right) >> 1);

    return (query(node * 2, left, mid, start, end) ^ query(node * 2 + 1, mid + 1, right, start, end));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (tree_size < n) {
        tree_size *= 2;
    }
    value.resize(n);
    seg.resize(tree_size * 2);
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

            update(1, 0, n - 1, start, end, v);
        }
        // Query
        else {
            int start, end;
            cin >> start >> end;

            cout << query(1, 0, n - 1, start, end) << '\n';
        }
    }

    return 0;
}