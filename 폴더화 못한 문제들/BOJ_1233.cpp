#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int s1, s2, s3;
vector<int> answer;

int main()
{
    cin >> s1 >> s2 >> s3;
    for (int i = 1; i <= s1; ++i) {
        for (int j = 1; j <= s2; ++j) {
            for (int k = 1; k <= s3; ++k) {
                answer.push_back(i + j + k);
            }
        }
    }
    sort(answer.begin(), answer.end());

    int maxCnt = -1;
    int maxCur = -1;
    int cnt = 0;
    int cur = -1;
    for (int i = 0; i < answer.size(); ++i) {
        if (cur == answer[i]) ++cnt;
        else if (cur == -1) {
            cnt = 1;
            cur = answer[i];
        }
        else if (cur != answer[i]) {
            if (maxCnt < cnt) {
                maxCnt = cnt;
                maxCur = cur;
            }
            cnt = 1;
            cur = answer[i];
        }
    }
    cout << maxCur << '\n';

    return 0;
}