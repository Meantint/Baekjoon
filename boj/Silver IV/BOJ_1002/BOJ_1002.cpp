#include <iostream>
#include <tuple>

#define PII pair<int, int>

using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int X = x1 - x2;
        int Y = y1 - y2;
        int R1 = r1 + r2;
        int R2 = r1 - r2;

        // 중점과 반지름 길이가 같다면 무한대
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            cout << "-1" << '\n';
        }
        // 중점이 같지만 반지름 길이가 다르다면 0
        else if (x1 == x2 && y1 == y2 && r1 != r2) {
            cout << '0' << '\n';
        }
        // 중점 사이의 거리가 반지름을 합친 것보다 더 크다면 만날 수 없다.
        else if (X * X + Y * Y > R1 * R1) {
            cout << '0' << '\n';
        }
        // 중점 사이의 거리가 반지름을 합친 것과 같다면 한 점에서 만난다.
        else if (X * X + Y * Y == R1 * R1) {
            cout << '1' << '\n';
        }
        // 중점 사이의 거리가 반지름을 합친 것보다 더 작을 경우
        else {
            // 중점 사이의 거리와 반지름 길이의 차이가 같을 경우 한 점에서 만난다.
            if (X * X + Y * Y == R2 * R2) {
                cout << '1' << '\n';
            }
            // 중점 사이의 거리가 반지름 길이의 차이보다 작을 경우 만나지 않는다.
            else if (X * X + Y * Y < R2 * R2) {
                cout << '0' << '\n';
            }
            // 중점 사이의 거리가 반지름 길이의 차이보다 클 경우 두 점에서 만난다.
            else {
                cout << '2' << '\n';
            }
        }
    }

    return 0;
}