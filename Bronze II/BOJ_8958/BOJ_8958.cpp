#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, point = 1, answer = 0;

string str;

int main()
{
    cin >> t;
    while (t--) {
        point = 1;
        answer = 0;

        cin >> str;
        for (auto& s : str) {
            if (s == 'O') {
                answer += point;
                ++point;
            }
            else {
                point = 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}