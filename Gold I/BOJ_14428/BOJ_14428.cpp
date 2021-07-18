#include <iostream>
#include <vector>

#define PII pair<int, int>
#define INF 2112345678

using namespace std;

int n, m;
vector<int> cost;
vector<pair<int, int>> seg;

PII init(int node, int left, int right)
{
    if (left == right) {
        return seg[node] = make_pair(cost[left], left);
    }

    int mid = ((left + right) >> 1);
    PII left_info = init(node * 2, left, mid);
    PII right_info = init(node * 2 + 1, mid + 1, right);

    if (left_info.first == right_info.first) {
        if (left_info.second < right_info.second) {
            seg[node] = left_info;
        }
        else {
            seg[node] = right_info;
        }
        return seg[node];
    }
    return seg[node] = (left_info.first < right_info.first ? left_info : right_info);
}

PII update(int node, int left, int right, int target_index, int new_value)
{
    if (target_index < left || right < target_index) {
        return seg[node];
    }

    if (left != right) {
        int mid = ((left + right) >> 1);
        PII left_info = update(node * 2, left, mid, target_index, new_value);
        PII right_info = update(node * 2 + 1, mid + 1, right, target_index, new_value);

        if (left_info.first == right_info.first) {
            if (left_info.second < right_info.second) {
                seg[node] = left_info;
            }
            else {
                seg[node] = right_info;
            }
            return seg[node];
        }
        return seg[node] = (left_info.first < right_info.first ? left_info : right_info);
    }
    else {
        return seg[node] = make_pair(new_value, target_index);
    }
}

PII query(int node, int left, int right, int start, int end)
{
    if (right < start || end < left) {
        return make_pair(INF, INF);
    }
    if (start <= left && right <= end) {
        return seg[node];
    }

    int mid = ((left + right) >> 1);
    PII left_info = query(node * 2, left, mid, start, end);
    PII right_info = query(node * 2 + 1, mid + 1, right, start, end);

    if (left_info.first == right_info.first) {
        if (left_info.second < right_info.second) {
            return left_info;
        }
        else {
            return right_info;
        }
    }
    return (left_info.first < right_info.first ? left_info : right_info);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cost.resize(n);

    int seg_size = 1;
    while (seg_size < n) {
        seg_size *= 2;
    }
    seg.resize(seg_size * 2);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    init(1, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int case_num;
        cin >> case_num;

        // Change
        if (case_num == 1) {
            int target_index, new_value;
            cin >> target_index >> new_value;

            update(1, 0, n - 1, target_index - 1, new_value);
        }
        // Query
        else {
            int start, end;
            cin >> start >> end;

            cout << query(1, 0, n - 1, start - 1, end - 1).second + 1 << '\n';
        }
    }

    return 0;
}