#include <iostream>
#include <vector>

#define ll long long
#define MOD (ll)1000000007
#define DEFAULT make_pair((ll)1, (ll)0)

using namespace std;

int n, m;
vector<int> value;
vector<ll> seg;
vector<pair<ll, ll>> lazy;

using namespace std;

void propagate(int node, int left, int right)
{
    if (lazy[node] != DEFAULT) {
        if (left != right) {
            lazy[node * 2].first *= lazy[node].first;
            lazy[node * 2].second = lazy[node * 2].second * lazy[node].first + lazy[node].second;
            lazy[node * 2 + 1].first *= lazy[node].first;
            lazy[node * 2 + 1].second = lazy[node * 2 + 1].second * lazy[node].first + lazy[node].second;

            lazy[node * 2].first %= MOD;
            lazy[node * 2].second %= MOD;
            lazy[node * 2 + 1].first %= MOD;
            lazy[node * 2 + 1].second %= MOD;
        }
        seg[node] = (lazy[node].first * seg[node] + (right - left + 1) * lazy[node].second) % MOD;
        lazy[node] = DEFAULT;
    }
}

int init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = value[left];
    }

    int mid = ((left + right) >> 1);
    return seg[node] = (init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right)) % MOD;
}

void update(int node, int left, int right, int start, int end, int case_num, ll v)
{
    propagate(node, left, right);

    if (end < left || right < start) {
        return;
    }
    if (start <= left && right <= end) {
        if (case_num == 1) {
            lazy[node].second += v;
            lazy[node].second %= MOD;
        }
        else if (case_num == 2) {
            lazy[node].first *= v;
            lazy[node].first %= MOD;
            lazy[node].second *= v;
            lazy[node].second %= MOD;
        }
        else {
            lazy[node] = make_pair(0, v);
        }
        propagate(node, left, right);

        return;
    }

    int mid = ((left + right) >> 1);
    update(node * 2, left, mid, start, end, case_num, v);
    update(node * 2 + 1, mid + 1, right, start, end, case_num, v);
    seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;

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

    return (query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end)) % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    value.resize(n);

    int tree_size = 1;
    while (tree_size < n) {
        tree_size *= 2;
    }
    seg.resize(tree_size * 2);
    lazy.resize(tree_size * 2, DEFAULT);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    init(1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int case_num;
        cin >> case_num;

        // Update
        if (case_num < 4) {
            int x, y, v;
            cin >> x >> y >> v;

            update(1, 0, n - 1, x - 1, y - 1, case_num, v);
        }
        // Query
        else {
            int x, y;
            cin >> x >> y;

            cout << query(1, 0, n - 1, x - 1, y - 1) << '\n';
        }
    }

    return 0;
}