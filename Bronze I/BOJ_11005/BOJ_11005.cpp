#include <iostream>
#include <string>

using namespace std;

int n, b;
string answer = "";

int main()
{
    cin >> n >> b;

    while (n != 0) {
        int temp = n % b;
        if (temp < 10) {
            answer = to_string(temp) + answer;
        }
        else {
            answer = (char)((temp - 10) + 'A') + answer;
        }

        n /= b;
    }

    cout << answer << '\n';

    return 0;
}