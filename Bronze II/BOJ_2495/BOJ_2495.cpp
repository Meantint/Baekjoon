#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    for (int t = 0; t < 3; ++t) {
        cin >> str;

        int max_count = 1;

        int cur_count = 1;
        char prev = str[0];

        int str_size = str.size();
        for (int i = 1; i < str_size; ++i) {
            if (prev == str[i]) {
                ++cur_count;
            }
            else {
                if (max_count < cur_count) {
                    max_count = cur_count;
                }
                prev = str[i];
                cur_count = 1;
            }
        }
        if (max_count < cur_count) {
            max_count = cur_count;
        }

        cout << max_count << '\n';
    }

    return 0;
}