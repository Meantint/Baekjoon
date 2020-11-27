#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt, idx, cond;
vector<bool> v;
vector<int> answer;

int main()
{
    cin >> n >> k;
    v.resize(n, true);
    idx = k - 1;
    answer.push_back(idx);
    v[idx] = false;
    ++cnt;
    // cnt가 n이 될 때까지 반복
    while (cnt != n) {
        cond = 0;
        while (1) {
            // 아직 제거 안됐다면
            if (v[idx]) {
                ++cond;
                // 만약 cond == k라면
                if (cond == k) {
                    ++cnt;
                    answer.push_back(idx);
                    v[idx] = false;

                    break;
                }
            }
            ++idx;
            idx %= n;
        }
    }

    // 마지막 원소 뒤는 ", "가 안붙기 때문에 size를 하나 작게 받아준다.
    int size = n - 1;
    // output
    cout << '<';
    for (int i = 0; i < size; ++i) {
        cout << answer[i] + 1 << ", ";
    }
    cout << answer.back() + 1 << '>';

    return 0;
}