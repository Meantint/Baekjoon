#include <iostream>

#define PII pair<int, int>

using namespace std;

int a, b;
PII answer;

int gcd(int n1, int n2)
{
    // n1보다 n2가 더 크다면 swap 해준다.
    if (n2 > n1) {
        swap(n1, n2);
    }
    // n1이 n2로 나누어 떨어진다면 n2를 리턴
    if (n1 % n2 == 0) {
        return n2;
    }
    // 나누어 떨어지지 않는다면 gcd(n2, n1 % n2)를 리턴
    else {
        return gcd(n2, n1 % n2);
    }
}

int main()
{
    cin >> a >> b;
    answer.first = gcd(a, b);
    answer.second = a * b / answer.first;

    cout << answer.first << '\n'
         << answer.second << '\n';

    return 0;
}