#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int n;
// (min, max)
PII answer = make_pair(1000100, -1000100);
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for (auto& val : v) {
        cin >> val;
    }
    for (auto& val : v) {
        // 현재까지의 최솟값보다 크다면
        if (val < answer.first) {
            answer.first = val;
        }
        // 현재까지의 최댓값보다 크다면
        if (val > answer.second) {
            answer.second = val;
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';

    return 0;
}