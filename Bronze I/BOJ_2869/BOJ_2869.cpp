#include <iostream>

using namespace std;

int a, b, v;
int ret;

int main()
{
    cin >> a >> b >> v;

    ret = 1;
    v -= a;                  // 마지막 날을 빼준다.
    ret += (v / (a - b));    // 낮과 밤을 합친 거리로 남은 거리를 나눠준다.
    if (v % (a - b) != 0) {  // 낮과 밤을 합친 거리로 딱 나눠떨어지지 않는다면 1을 더해줘야한다.
        ++ret;
    }

    cout << ret << '\n';

    return 0;
}