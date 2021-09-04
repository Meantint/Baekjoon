#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int tc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {  //test case
        // input & init
        string order, str;
        int n;
        vector<int> info;
        cin >> order >> n >> str;

        // create array
        if (n != 0) {
            int val = 0;
            int size = str.size();
            for (int i = 1; i < size; ++i) {
                if (str[i] == ',' || str[i] == ']') {
                    info.push_back(val);
                    val = 0;
                }
                else {
                    val *= 10;
                    val += (str[i] - '0');
                }
            }
        }

        // order
        bool isRv = false;  // 뒤집혔는지
        int low = 0, high = info.size();
        int oSize = order.size();
        for (int i = 0; i < oSize; ++i) {
            if (order[i] == 'R') {
                isRv = !isRv;
            }
            else {  // 'D'
                if (isRv) {
                    --high;
                }
                else {
                    ++low;
                }
            }
        }
        if (low > high) {
            cout << "error";
        }
        else if (low == high) {
            cout << "[]";
        }
        else {
            cout << '[';
            if (isRv) {
                for (int i = high - 1; i > low; --i) {
                    cout << info[i] << ',';
                }
                cout << info[low];
            }
            else {
                for (int i = low; i < high - 1; ++i) {
                    cout << info[i] << ',';
                }
                cout << info[high - 1];
            }
            cout << ']';
        }
        cout << '\n';
    }

    return 0;
}