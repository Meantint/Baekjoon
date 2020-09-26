#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    string str;
    cin >> n >> m >> str;

    int answer = 0;
    int cnt = 0;
    int size = m - 2;
    for (int i = 0; i < size; ++i) {
        if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            ++cnt;
            if (cnt == n) {
                ++answer;
                --cnt;
            }
            ++i;
        }
        else {
            cnt = 0;
        }
    }
    cout << answer << '\n';

    return 0;
}