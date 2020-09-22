#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define PII pair<int, int>
#define INF 2000000000

using namespace std;

int N, M;
vector<PII> seg;
vector<int> val;

void init(int node, int start, int end)
{
    if (start == end) {
        seg[node].first = val[start];
        seg[node].second = val[start];
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    seg[node] = make_pair(min(seg[node * 2].first, seg[node * 2 + 1].first),
                          max(seg[node * 2].second, seg[node * 2 + 1].second));
}

PII find(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return make_pair(INF, -1);
    if (left <= start && end <= right) return seg[node];

    PII p1 = find(node * 2, start, (start + end) / 2, left, right);
    PII p2 = find(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int h = (int)ceil(log2(N));
    seg.resize((1 << (h + 1)), make_pair(INF, -1));
    val.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> val[i];
    }
    init(1, 1, N);
    for (int i = 0; i < M; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        PII ans = find(1, 1, N, n1, n2);
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}