#include <iostream>
#include <string>

using namespace std;

int answer = 0;
string str;

int main()
{
    cin >> str;
    for (auto ch : str) {
        if (ch == ',') {
            ++answer;
        }
    }

    cout << answer + 1 << '\n';

    return 0;
}