#include <cmath>
#include <iostream>

using namespace std;

int t;
int x_1, y_1, r_1, x_2, y_2, r_2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;

        // 원의 중점이 같고
        if (x_1 == x_2 && y_1 == y_2) {
            // 반지름도 같을 때
            if (r_1 == r_2) {
                cout << "-1\n";
            }
            // 반지름만 다를 때
            else {
                cout << "0\n";
            }
        }
        else {
            int pp = pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2);
            int rr = pow(r_1 + r_2, 2);
            if (pp > rr) {
                cout << "0\n";
            }
            else if (pp == rr) {
                cout << "1\n";
            }
            else {
                int new_rr = pow(r_1 - r_2, 2);
                if (pp < new_rr) {
                    cout << "0\n";
                }
                else if (pp == new_rr) {
                    cout << "1\n";
                }
                else {
                    cout << "2\n";
                }
            }
        }
    }

    return 0;
}