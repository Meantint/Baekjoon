#include <iostream>
#include <string>

using namespace std;

string target;
int max_size;

int main()
{
    cin >> target >> max_size;

    int target_num = stoi(target);
    int target_size = target.size();

    int t = 0;
    while (t < target_num && max_size != 0) {
        ++t;
        if (target_size <= max_size) {
            cout << target;
            max_size -= target_size;
        }
        else {
            cout << target.substr(0, max_size);
            max_size = 0;
        }
    }
    cout << '\n';

    return 0;
}