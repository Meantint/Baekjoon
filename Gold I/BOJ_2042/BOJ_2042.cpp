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
        seg[node] = cost[left];
    }
    else {
        int mid = ((left + right) >> 1);
        ll left_tree = init(node * 2, left, mid);
        ll right_tree = init(node * 2 + 1, mid + 1, right);

        seg[node] = left_tree + right_tree;
    }

    return seg[node];
}

void update(int node, int left, int right, int target_index, ll value_diff)
{
    if (left > target_index || target_index > right) {
        return;
    }

    seg[node] += value_diff;
    if (left != right) {
        int mid = ((left + right) >> 1);
        update(node * 2, left, mid, target_index, value_diff);
        update(node * 2 + 1, mid + 1, right, target_index, value_diff);
    }
}

ll query(int node, int left, int right, int target_left, int target_right)
{
    // 범위에서 완전히 벗어난 경우
    if (target_right < left || target_left > right) {
        return 0;
    }
    // 범위 안에 완전히 속해 있는 경우
    if (target_left <= left && right <= target_right) {
        return seg[node];
    }
    else {
        int mid = ((left + right) >> 1);
        ll left_query = query(node * 2, left, mid, target_left, target_right);
        ll right_query = query(node * 2 + 1, mid + 1, right, target_left, target_right);

        return left_query + right_query;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
            ll value;
            cin >> target_index >> value;

            update(1, 0, n - 1, target_index - 1, value - cost[target_index - 1]);
            cost[target_index - 1] = value;
        }
        // Query
        else {
            int target_left, target_right;
            cin >> target_left >> target_right;

            cout << query(1, 0, n - 1, target_left - 1, target_right - 1) << '\n';
        }
    }

    return 0;
}