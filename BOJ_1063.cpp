#include <bits/stdc++.h>

using namespace std;

int main()
{
        string king, stone;
        cin >> king >> stone;
        int T;
        cin >> T;

        for (int i = 0; i < T; ++i) {
                string str;
                cin >> str;

                if (str == "R") {
                        if (king[0] == 'H')
                                continue;
                        ++king[0];
                        if (king == stone) {
                                if (stone[0] == 'H')
                                        --king[0];
                                else
                                        ++stone[0];
                        }
                }
                else if (str == "L") {
                        if (king[0] == 'A')
                                continue;
                        --king[0];
                        if (king == stone) {
                                if (stone[0] == 'A')
                                        ++king[0];
                                else
                                        --stone[0];
                        }
                }
                else if (str == "B") {
                        if (king[1] == '1')
                                continue;
                        --king[1];
                        if (king == stone) {
                                if (stone[1] == '1')
                                        ++king[1];
                                else
                                        --stone[1];
                        }
                }
                else if (str == "T") {
                        if (king[1] == '8')
                                continue;
                        ++king[1];
                        if (king == stone) {
                                if (stone[1] == '8')
                                        --king[1];
                                else
                                        ++stone[1];
                        }
                }
                else if (str == "RT") {
                        if (king[0] == 'H' || king[1] == '8')
                                continue;
                        ++king[0];
                        ++king[1];
                        if (king == stone) {
                                if (stone[0] == 'H' || stone[1] == '8') {
                                        --king[0];
                                        --king[1];
                                }
                                else {
                                        ++stone[0];
                                        ++stone[1];
                                }
                        }
                }
                else if (str == "LT") {
                        if (king[0] == 'A' || king[1] == '8')
                                continue;
                        --king[0];
                        ++king[1];
                        if (king == stone) {
                                if (stone[0] == 'A' || stone[1] == '8') {
                                        ++king[0];
                                        --king[1];
                                }
                                else {
                                        --stone[0];
                                        ++stone[1];
                                }
                        }
                }
                else if (str == "RB") {
                        if (king[0] == 'H' || king[1] == '1')
                                continue;
                        ++king[0];
                        --king[1];
                        if (king == stone) {
                                if (stone[0] == 'H' || stone[1] == '1') {
                                        --king[0];
                                        ++king[1];
                                }
                                else {
                                        ++stone[0];
                                        --stone[1];
                                }
                        }
                }
                else if (str == "LB") {
                        if (king[0] == 'A' || king[1] == '1')
                                continue;
                        --king[0];
                        --king[1];
                        if (king == stone) {
                                if (stone[0] == 'A' || stone[1] == '1') {
                                        ++king[0];
                                        ++king[1];
                                }
                                else {
                                        --stone[0];
                                        --stone[1];
                                }
                        }
                }
        }
        cout << king << '\n'
             << stone << '\n';

        return 0;
}