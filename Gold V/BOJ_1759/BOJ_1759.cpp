#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<char> arr;

int main()
{
    cin >> n >> m;
    arr.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> comb(m, 1);
    for (int i = 0; i < n; ++i) {
        comb[i] = 0;
    }

    do {
        int vowels = 0;
        int consonants = 0;
        string temp = "";
        for (int i = 0; i < m; ++i) {
            if (comb[i] == 0) {
                temp += arr[i];
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                    ++vowels;
                }
                else {
                    ++consonants;
                }
            }
        }
        if (vowels >= 1 && consonants >= 2) {
            cout << temp << '\n';
        }
    } while (next_permutation(comb.begin(), comb.end()));

    return 0;
}