#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    cin >> str;
    int left = 0;
    int right = str.size() - 1;

    int answer = 1;
    while (left < right) {
        if (str[left] != str[right]) {
            answer = 0;
            break;
        }

        ++left;
        --right;
    }

    cout << answer << '\n';

    return 0;
}