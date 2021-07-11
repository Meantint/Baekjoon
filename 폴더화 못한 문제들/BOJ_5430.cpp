#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        string answer = "";
        string order;
        cin >> order;

        int size;
        cin >> size;

        string num;
        cin >> num;
        vector<int> v;
        int n = 0;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] >= '0' && num[i] <= '9') {
                n *= 10;
                n += num[i] - '0';
            }
            else {
                v.push_back(n);
                n = 0;
            }
        }
        if (num.size() == 2) {
            v.pop_back();
        }
        int st, ed, cur;
        bool isErr = false;
        // cur 0 : 앞, cur 1 : reverse
        cur = 0;
        st = 0;
        ed = v.size() - 1;
        for (int i = 0; i < order.size(); ++i) {
            if (order[i] == 'R') {
                cur = (cur + 1) % 2;
            }
            else {
                if (st > ed) {
                    isErr = true;
                    // cout << "Error!\n";
                    break;
                }
                if (cur == 0) {
                    v[st] = -1;
                    ++st;
                }
                else {
                    v[ed] = -1;
                    --ed;
                }
            }
        }
        if (isErr) {
            cout << "error" << '\n';
        }
        else {
            answer += '[';
            if (st > ed) {
                answer += ']';
            }
            else if (cur == 0) {
                for (int i = st; i < ed; ++i) {
                    answer += to_string(v[i]);
                    answer += ',';
                }
                if (v[ed] != -1) {
                    answer += to_string(v[ed]);
                }
                answer += ']';
            }
            else {
                for (int i = ed; i > st; --i) {
                    answer += to_string(v[i]);
                    answer += ',';
                }
                if (v[st] != -1) {
                    answer += to_string(v[st]);
                }
                answer += ']';
            }
            cout << answer << '\n';
        }
    }

    return 0;
}