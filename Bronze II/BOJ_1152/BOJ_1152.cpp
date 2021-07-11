#include <iostream>

using namespace std;

string s;
int answer = 0;

int main()
{
    answer = 0;

    getline(cin, s);

    int s_size = s.size();
    for (int i = 0; i < s_size; ++i) {
        if (s[i] == ' ') {
            continue;
        }

        int temp = i;
        while (temp < s_size && s[temp] != ' ') {
            ++temp;
        }
        i = temp - 1;  // 단어의 끝부분으로 인덱스 변경
        ++answer;
    }

    cout << answer << '\n';

    return 0;
}