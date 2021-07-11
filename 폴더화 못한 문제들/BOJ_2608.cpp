#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int cal(string str)
{
    int realnum = 0;
    int size = str.size();
    for (int i = 0; i < size; ++i) {
        bool isTwo = false;
        if (i + 1 < size) {
            if (str.substr(i, 2) == "IV") {
                realnum += 4;
                isTwo = true;
                ++i;
            }
            else if (str.substr(i, 2) == "IX") {
                realnum += 9;
                isTwo = true;
                ++i;
            }
            else if (str.substr(i, 2) == "XL") {
                realnum += 40;
                isTwo = true;
                ++i;
            }
            else if (str.substr(i, 2) == "XC") {
                realnum += 90;
                isTwo = true;
                ++i;
            }
            else if (str.substr(i, 2) == "CD") {
                realnum += 400;
                isTwo = true;
                ++i;
            }
            else if (str.substr(i, 2) == "CM") {
                realnum += 900;
                isTwo = true;
                ++i;
            }
        }
        if (isTwo == false) {
            if (str[i] == 'I') {
                realnum += 1;
            }
            else if (str[i] == 'V') {
                realnum += 5;
            }
            else if (str[i] == 'X') {
                realnum += 10;
            }
            else if (str[i] == 'L') {
                realnum += 50;
            }
            else if (str[i] == 'C') {
                realnum += 100;
            }
            else if (str[i] == 'D') {
                realnum += 500;
            }
            else if (str[i] == 'M') {
                realnum += 1000;
            }
        }
    }
    return realnum;
}

int main()
{
    map<int, string> m;
    map<int, string> except;
    m[1] = "I";
    m[5] = "V";
    m[10] = "X";
    m[50] = "L";
    m[100] = "C";
    m[500] = "D";
    m[1000] = "M";
    except[4] = "IV";
    except[9] = "IX";
    except[40] = "XL";
    except[90] = "XC";
    except[400] = "CD";
    except[900] = "CM";

    string str1, str2;
    cin >> str1 >> str2;
    int sum = 0;
    sum = cal(str1) + cal(str2);
    string str = to_string(sum);

    cout << sum << '\n';
    string answer = "";

    int size = str.size();
    for (int i = 0; i < size; ++i) {
        int realSize = str.size() - i - 1;
        if (str[i] == '9' || str[i] == '4') {
            if (realSize == 2) {
                answer += except[(str[i] - '0') * 100];
            }
            else if (realSize == 1) {
                answer += except[(str[i] - '0') * 10];
            }
            else if (realSize == 0) {
                answer += except[(str[i] - '0') * 1];
            }
            str[i] = '0';
            continue;
        }
        while (str[i] != '0') {
            if (str[i] - '0' >= 5) {
                answer += m[5 * pow(10, realSize)];
                str[i] = str[i] - 5;
            }
            else {
                answer += m[1 * pow(10, realSize)];
                str[i] = str[i] - 1;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}