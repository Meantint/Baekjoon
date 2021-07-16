#include <iostream>
#include <vector>

#define INF 2112345678

using namespace std;

int n, m;
vector<int> cost;
vector<int> seg;

int init(int node, int left, int right)
{
    if (left == right) {
        return (seg[node] = cost[left]);
    }
    else {
        int mid = ((left + right) >> 1);
        int left_value = init(node * 2, left, mid);
        int right_value = init(node * 2 + 1, mid + 1, right);

        return seg[node] = (left_value < right_value ? left_value : right_value);
    }
}

int query(int node, int left, int right, int start, int end)
{
    // 범위 벗어난다면
    if (end < left || right < start) {
        return INF;
    }
    if (start <= left && right <= end) {
        return seg[node];
    }
    else {
        int mid = ((left + right) >> 1);
        int left_value = query(node * 2, left, mid, start, end);
        int right_value = query(node * 2 + 1, mid + 1, right, start, end);

        return left_value < right_value ? left_value : right_value;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cost.resize(n);

    int seg_size = 1;
    while (seg_size < n) {
        seg_size <<= 1;
    }
    seg.resize(seg_size * 2, INF);

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    init(1, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;

        cout << query(1, 0, n - 1, start - 1, end - 1) << '\n';
    }

    return 0;
}