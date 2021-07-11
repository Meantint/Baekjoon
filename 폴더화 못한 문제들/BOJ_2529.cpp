#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<char> deungho;

int main()
{
    cin >> n;
    deungho.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> deungho[i];
    }

    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(9 - i);
    }
    do {
        bool isTrue = true;
        for (int i = 0; i < n; ++i) {
            if (deungho[i] == '<') {
                if (v[i] < v[i + 1]) continue;
                else {
                    isTrue = false;
                    break;
                }
            }
            else {
                if (v[i] > v[i + 1]) continue;
                else {
                    isTrue = false;
                    break;
                }
            }
        }
        if (isTrue) {
            for (int i = 0; i < n + 1; ++i) {
                cout << v[i];
            }
            cout << '\n';
            break;
        }
    } while (prev_permutation(v.begin(), v.end()));

    v.clear();
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    do {
        bool isTrue = true;
        for (int i = 0; i < n; ++i) {
            if (deungho[i] == '<') {
                if (v[i] < v[i + 1]) continue;
                else {
                    isTrue = false;
                    break;
                }
            }
            else {
                if (v[i] > v[i + 1]) continue;
                else {
                    isTrue = false;
                    break;
                }
            }
        }
        if (isTrue) {
            for (int i = 0; i < n + 1; ++i) {
                cout << v[i];
            }
            cout << '\n';
            break;
        }
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}