#include <bits/stdc++.h>

using namespace std;

int Answer;
int n;

int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {

        Answer = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            Answer = (Answer ^ num);
        }

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}