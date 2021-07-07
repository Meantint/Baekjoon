// cin.eof()가 제대로 출력됐는지 보기 위해서는 input.txt에 빈 개행을 하나 넣어줘야한다.
#include <iostream>

using namespace std;

int n, a, b;

int main()
{
    while (1) {
        cin >> a >> b;
        // cin.eof(): cin으로 받은게 없다면 true
        if (cin.eof()) {
            break;
        }
        cout << a + b << '\n';
    }

    return 0;
}