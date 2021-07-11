#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define INF 2112345678

using namespace std;

int N;
vector<int> segTree;
vector<vector<int>> rankP;

void update(int node, int start, int end, int index, int val)
{
    if (index < start || index > end) return;
    // 단말 노드라면
    if (start == end) {
        segTree[node] = val;
        while (node >= 1) {
            node /= 2;
            segTree[node] = min(segTree[node * 2], segTree[node * 2 + 1]);
        }
        return;
    }
    else {
        update(node * 2, start, (start + end) / 2, index, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    }
}

int find(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return INF;
    if (left <= start && end <= right) return segTree[node];
    return min(find(node * 2, start, (start + end) / 2, left, right),
               find(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main()
{
    cin >> N;
    rankP.resize(N, vector<int>(3, 0));
    int h = (int)log2(N) + 1;
    // 세그먼트 트리의 사이즈 확정 및 초기화
    segTree.resize((1 << (h + 1)), INF);
    // cout << "segTree Size : " << segTree.size() << '\n';
    for (int re = 0; re < 3; ++re) {
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            rankP[num - 1][re] = i + 1;
        }
    }
    // 첫 번째 시험 순위로 오름차순 정렬
    sort(rankP.begin(), rankP.end());
    // for (int i = 0; i < rankP.size(); ++i) {
    //     cout << rankP[i][0] << ", " << rankP[i][1] << ", " << rankP[i][2] << endl;
    // }

    int answer = 0;
    for (int i = 0; i < rankP.size(); ++i) {
        // 1 ~ rankP[i][1] 범위에서 나온 최솟값보다
        // 현재 학생의 3번째 과목의 등수가 더 높다면 ++answer
        if (find(1, 1, N, 1, rankP[i][1]) > rankP[i][2]) {
            // cout << i + 1 << " is Daedan\n";
            ++answer;
        }
        update(1, 1, N, rankP[i][1], rankP[i][2]);
    }
    cout << answer << '\n';

    return 0;
}