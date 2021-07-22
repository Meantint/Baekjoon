#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, q;
int tree_size = 1;
vector<ll> value;
vector<ll> seg;

ll init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = value[left];
    }

    int mid = ((left + right) >> 1);

    return seg[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int target_index, ll diff)
{
    if (target_index < left || right < target_index) {
        return;
    }

    seg[node] += diff;
    if (left != right) {
        int mid = ((left + right) >> 1);
        update(node * 2, left, mid, target_index, diff);
        update(node * 2 + 1, mid + 1, right, target_index, diff);
    }
}

ll query(int node, int left, int right, int start, int end)
{
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

    cin >> n >> q;
    while (tree_size < n) {
        tree_size *= 2;
    }
    value.resize(n);
    seg.resize(tree_size * 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < q; ++i) {
        int x, y, target_index;
        ll v;
        cin >> x >> y >> target_index >> v;

        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }

        cout << query(1, 0, n - 1, x - 1, y - 1) << '\n';
        update(1, 0, n - 1, target_index - 1, v - value[target_index - 1]);
        value[target_index - 1] = v;
    }

    return 0;
}