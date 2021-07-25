#include <iostream>
#include <string>

using namespace std;

string l, r;
char op;

int main()
{
    cin >> l >> op >> r;

    int l_size = l.size();
    int r_size = r.size();
    int max_size = (l_size < r_size ? r_size : l_size);

    string answer = "";
    if (op == '+') {
        answer.resize(max_size, '0');
        if (l_size == r_size) {
            answer[0] = '2';
        }
        else {
            answer[max_size - r_size] = '1';
            answer[max_size - l_size] = '1';
        }
    }
    else {
        answer.resize(l_size + r_size - 1, '0');
        answer[0] = '1';
    }

    cout << answer << '\n';

    return 0;
}