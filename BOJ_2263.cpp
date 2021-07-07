// 재귀 함수 작성 시 범위에 유의!
// 특히 매개변수가 배열의 index를 가리킬 때

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
vector<int> pos;
vector<int> answer;

void print(int in_st, int in_ed, int post_st, int post_ed, int target)
{
    answer.push_back(target);
    if (in_st == in_ed) {
        return;
    }
    // target index 찾음
    int idx = pos[target - 1];
    int leftNext = post_st + idx - 1 - in_st;
    int rightNext = post_ed - 1;
    // printf("left  %d : (%d, %d, %d, %d, %d)\n", target, in_st, idx - 1, post_st, leftNext, postorder[leftNext]);
    if (in_st <= idx - 1)
        print(in_st, idx - 1, post_st, leftNext, postorder[leftNext]);
    // printf("right %d : (%d, %d, %d, %d, %d)\n", target, idx + 1, in_ed, leftNext + 1, rightNext, postorder[rightNext]);
    if (idx + 1 <= in_ed)
        print(idx + 1, in_ed, leftNext + 1, rightNext, postorder[rightNext]);

    return;
}

int main()
{
    cin >> n;
    inorder = vector<int>(n, 0);
    postorder = vector<int>(n, 0);
    pos = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
        pos[inorder[i] - 1] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    print(0, n - 1, 0, n - 1, postorder.back());
    int aSize = answer.size();
    for (int i = 0; i < aSize; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}