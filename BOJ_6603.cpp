#include <bits/stdc++.h>

using namespace std;

int main()
{
        int T;
        while (1) {
                cin >> T;
                if (T == 0)
                        break;

                vector<int> vec(T, 0);
                for (int i = 0; i < T; ++i) {
                        cin >> vec[i];
                }
                // 조합을 위한 com 변수 선언
                vector<int> com(T, 0);
                for (int i = 0; i < 6; ++i) {
                        com[i] = 1;
                }
                for (int i = 6; i < T; ++i) {
                        com[i] = 0;
                }

                do {
                        for (int i = 0; i < T; ++i) {
                                if (com[i] == 1) {
                                        cout << vec[i] << ' ';
                                }
                        }
                        cout << '\n';
                } while (next_permutation(com.begin(), com.end(), greater<int>()));
                cout << '\n';
        }

        return 0;
}