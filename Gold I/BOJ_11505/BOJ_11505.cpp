#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int n, m, k;
vector<ll> cost;
vector<ll> seg;

ll init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = cost[left];
    }

    int mid = ((left + right) >> 1);
    ll left_value = init(node * 2, left, mid);
    ll right_value = init(node * 2 + 1, mid + 1, right);

    return seg[node] = (left_value * right_value) % (ll)1000000007;
}

ll update(int node, int left, int right, int target_index, ll new_value)
{
    if (target_index < left || right < target_index) {
        return seg[node];
    }
    if (left != right) {
        int mid = ((left + right) >> 1);
        ll left_value = update(node * 2, left, mid, target_index, new_value);
        ll right_value = update(node * 2 + 1, mid + 1, right, target_index, new_value);

        return seg[node] = (left_value * right_value) % (ll)1000000007;
    }
    else {
        return seg[node] = cost[left] = new_value;
    }
}

ll query(int node, int left, int right, int start, int end)
{
    if (end < left || right < start) {
        return 1;
    }
    if (start <= left && right <= end) {
        return seg[node];
    }

    // 단말노드가 아니라면
    if (left != right) {
        int mid = ((left + right) >> 1);
        ll left_value = query(node * 2, left, mid, start, end);
        ll right_value = query(node * 2 + 1, mid + 1, right, start, end);

        return (left_value * right_value) % (ll)1000000007;
    }
}

int main()
{
    cin >> n >> m >> k;
    cost.resize(n);

    int seg_size = 1;
    while (seg_size < n) {
        seg_size <<= 1;
    }
    seg.resize(seg_size * 2, 0);

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    init(1, 0, n - 1);
    for (int i = 0; i < m + k; ++i) {
        int case_num;
        cin >> case_num;

        // Change
        if (case_num == 1) {
            int target_index;
            ll new_value;
            cin >> target_index >> new_value;

            update(1, 0, n - 1, target_index - 1, new_value);
            cost[target_index - 1] = new_value;
        }
        // Query
        else {
            int start, end;
            cin >> start >> end;

            cout << query(1, 0, n - 1, start - 1, end - 1) << '\n';
        }
    }
    cout << '\n';

    return 0;
}