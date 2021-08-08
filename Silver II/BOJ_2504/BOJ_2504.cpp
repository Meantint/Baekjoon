#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string str;
stack<char> s;
int lv_idx = 0;
vector<int> level_value(20, 0);

int main()
{
    cin >> str;

    for (auto ch : str) {
        if (ch == '[' || ch == '(') {
            s.push(ch);
            ++lv_idx;
        }
        else if (ch == ']') {
            if (s.empty() || s.top() != '[') {
                cout << 0 << '\n';

                return 0;
            }
            else {
                if (level_value[lv_idx] == 0) {
                    level_value[lv_idx] += 3;
                }
                else {
                    level_value[lv_idx] *= 3;
                }
                level_value[lv_idx - 1] += level_value[lv_idx];
                level_value[lv_idx] = 0;
                --lv_idx;
                s.pop();
            }
        }
        else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                cout << 0 << '\n';

                return 0;
            }
            else {
                if (level_value[lv_idx] == 0) {
                    level_value[lv_idx] += 2;
                }
                else {
                    level_value[lv_idx] *= 2;
                }
                level_value[lv_idx - 1] += level_value[lv_idx];
                level_value[lv_idx] = 0;
                --lv_idx;
                s.pop();
            }
        }
    }
    cout << level_value[0] << '\n';

    return 0;
}