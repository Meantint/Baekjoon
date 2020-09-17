#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end)
{
    // 단말 노드일 때
    if (start == end) {
        return tree[node] = a[start];
    }
    // 단말 노드가 아닐 때
    else {
        return tree[node] =
                   init(a, tree, node * 2, start, (start + end) / 2) +
                   init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
    }
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
    if (index < start || index > end) return;
    tree[node] += diff;
    // 단말 노드가 아니라면
    if (start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node * 2, start, (start + end) / 2, left, right) +
           sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> val(N);
    vector<long long> tree;
    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }
    int h = (int)ceil(log2(N));
    int tSize = (1 << (h + 1));
    tree.resize(tSize);

    init(val, tree, 1, 0, N - 1);
    for (int i = 0; i < M + K; ++i) {
        int c;
        cin >> c;
        // 값 변경
        if (c == 1) {
            int target;
            long long value;
            cin >> target >> value;
            update(tree, 1, 0, N - 1, target - 1, value - val[target - 1]);
            // cout << "Before : " << val[target - 1] << endl;
            // 아래 코드를 실행해줘야 하는 이유 :
            // 만약 이 코드를 실행하지 않고 같은 index의 target에 2번 이상 값을 바꾸게 된다면
            // 첫 번째(n = 1)는 정상적으로 작동하나(그 때는 바뀌기 전 val[target - 1] 값이 초기값(사용자가 넣은)이라 이상 없음)
            // n번째(n >= 2)는 n-1번째에서 갱신된 값과 n번째 들어온 값과의 차이를 update의 diff 자리에 넣어줘야 하는데
            // val[target - 1] = value; 가 실행되지 않았기 때문에 diff에 기존 초기값과 n번째 갱신 값의 차이가 들어가기 때문에
            // 정상적인 값이 출력되지 않는다.
            val[target - 1] = value;
            // cout << "After : " << val[target - 1] << endl;
        }
        // 구간 합
        else {
            int st, ed;
            cin >> st >> ed;
            cout << sum(tree, 1, 0, N - 1, st - 1, ed - 1) << '\n';
        }
    }

    return 0;
}