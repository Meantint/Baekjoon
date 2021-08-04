#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string str;

int solve()
{
    int ret = -1;
    int chance = 1;

    int left = 0, right = str.size() - 1;

    while (ret == -1 && left < right) {
        if (str[left] == str[right]) {
            ++left;
            --right;
        }
        else {
            if (chance == 1 && left + 1 <= right && str[left + 1] == str[right]) {
                int cp_left = left + 1;
                int cp_right = right;

                bool isPel = true;
                while (cp_left < cp_right) {
                    if (str[cp_left] == str[cp_right]) {
                        ++cp_left;
                        --cp_right;
                    }
                    else {
                        isPel = false;
                        break;
                    }
                }

                if (isPel) {
                    ret = 1;
                    break;
                }
            }
            if (chance == 1 && left <= right - 1 && str[left] == str[right - 1]) {
                int cp_left = left;
                int cp_right = right - 1;

                bool isPel = true;
                while (cp_left < cp_right) {
                    if (str[cp_left] == str[cp_right]) {
                        ++cp_left;
                        --cp_right;
                    }
                    else {
                        isPel = false;
                        break;
                    }
                }

                if (isPel) {
                    ret = 1;
                    break;
                }
            }
            ret = 2;
        }
    }

    if (ret == -1) {
        if (chance == 1) {
            ret = 0;
        }
        else {
            ret = 1;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> str;

        cout << solve() << '\n';
    }

    return 0;
}