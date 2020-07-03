#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n, k;
        cin >> n >> k;

        vector<bool> isDel(n, false);
        cout << '<';

        int ansCnt = 0;
        int idxCnt = 0;
        int idx = 0;
        int size = isDel.size();
        while (ansCnt < isDel.size() - 1) {
                if (!isDel[idx]) {
                        ++idxCnt;
                        if (idxCnt == k) {
                                cout << idx + 1 << ", ";
                                idxCnt = 0;
                                isDel[idx] = true;
                                ++ansCnt;
                        }
                }
                ++idx;
                idx %= n;
        }
        for (int i = 0; i < size; ++i) {
                if (!isDel[i])
                        cout << i + 1 << '>' << '\n';
        }

        return 0;
}