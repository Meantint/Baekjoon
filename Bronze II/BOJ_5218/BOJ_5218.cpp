#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int n;
string a, b;

int main()
{
    cin >> n;
    while (n--) {
        cin >> a >> b;

        cout << "Distances: ";
        int size = a.size();
        for (int i = 0; i < size; ++i) {
            int dist = (b[i] - a[i]);
            if (dist < 0) {
                dist += 26;
            }
            cout << dist << ' ';
        }
        cout << '\n';
    }

    return 0;
}