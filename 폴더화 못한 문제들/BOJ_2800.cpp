#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

vector<string> answer;
string eq;
PII conn[1 << 10];
int all;
int num_conn;
int tc = 0;

void dfs(int brCnt, int val)
{
        // cout << "brCnt : " << brCnt << ", " << "tc #" << ++tc << " : " << val << '\n';
        if (brCnt == 0) {
                if (val == (1 << num_conn) - 1)
                        return;

                string cp = eq;
                for (int i = 0; i < num_conn; ++i) {
                        if (((1 << i) & val) == 0) { // 괄호 잘쳐줘야함.. ㅠㅠ
                                cp[conn[1 << i].first] = cp[conn[1 << i].second] = ' ';
                        }
                }
                string tmp = "";
                int size = cp.size();
                for (int i = 0; i < size; ++i) {
                        if (cp[i] != ' ')
                                tmp += cp[i];
                }
                answer.push_back(tmp);
                // cout << "tc #" << tc << ", push\n";

                return;
        }
        dfs(--brCnt, (val << 1) | 0);
        ++brCnt;
        dfs(--brCnt, (val << 1) | 1);
}

int main()
{
        cin >> eq;
        int size = eq.size();
        int brCnt = 0;
        for (int i = 0; i < size; ++i) {
                if (eq[i] == '(') {
                        int idx = i;
                        int lv = 0;
                        while (++idx) {
                                if (eq[idx] == ')' && lv == 0) {
                                        conn[1 << brCnt].first = i;
                                        conn[1 << brCnt].second = idx;
                                        ++brCnt;
                                        break;
                                }
                                else if (eq[idx] == ')' && lv != 0) {
                                        --lv;
                                }
                                else if (eq[idx] == '(') {
                                        ++lv;
                                }
                        }
                }
        }
        num_conn = brCnt;
        dfs(--brCnt, 0);
        ++brCnt;
        dfs(--brCnt, 1);

        sort(answer.begin(), answer.end());
        string prev = answer[0];
        cout << answer[0] << '\n';
        size = answer.size();
        for (int i = 1; i < size; ++i) {
                if (prev != answer[i]) {
                        cout << answer[i] << '\n';
                        prev = answer[i];
                }
        }

        return 0;
}
