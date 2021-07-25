#include <iostream>
#include <string>

using namespace std;

int joi_count = 0;
int ioi_count = 0;
string joi_find = "JOI";
string ioi_find = "IOI";
string str;

int main()
{
    cin >> str;

    int size = str.size() - 2;
    for (int i = 0; i < size; ++i) {
        string temp = str.substr(i, 3);
        if (temp == joi_find) {
            ++joi_count;
        }
        else if (temp == ioi_find) {
            ++ioi_count;
        }
    }
    cout << joi_count << '\n'
         << ioi_count << '\n';

    return 0;
}