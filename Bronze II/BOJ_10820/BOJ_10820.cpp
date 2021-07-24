#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;

int main()
{
    while (getline(cin, str)) {
        vector<int> answer(4, 0);

        int size = str.size();
        for (int i = 0; i < size; ++i) {
            if ('a' <= str[i] && str[i] <= 'z') {
                ++answer[0];
            }
            else if ('A' <= str[i] && str[i] <= 'Z') {
                ++answer[1];
            }
            else if ('0' <= str[i] && str[i] <= '9') {
                ++answer[2];
            }
            else if (str[i] == ' ') {
                ++answer[3];
            }
        }

        for (auto ans : answer) {
            cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}