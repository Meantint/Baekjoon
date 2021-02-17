#include <iostream>

using namespace std;

char answer[100][130];
int a_size = -1;

char text[130];
int t_size = 0;

char base[130];
int b_size;

char name[130], symbol[130];
int n_idx = -1, s_idx = -1;

void solve()
{
    int idx = 0;

    // 베이스
    for (; idx < t_size; ++idx) {
        if (text[idx] == ' ') {
            b_size = idx;
            ++idx;

            break;
        }
        base[idx] = text[idx];
    }

    for (; idx < t_size; ++idx) {
        if ((text[idx] >= 'A' && text[idx] <= 'Z') || (text[idx] >= 'a' && text[idx] <= 'z')) {
            name[++n_idx] = text[idx];
        }
        else {
            while (text[idx] != ',' && text[idx] != ';') {
                symbol[++s_idx] = text[idx];
                ++idx;
            }

            ++a_size;
            for (int i = 0; i < b_size; ++i) {
                answer[a_size][i] = base[i];
            }
            for (int i = s_idx; i >= 0; --i) {
                if (symbol[i] == ']') {
                    answer[a_size][b_size + s_idx - i] = '[';
                }
                else if (symbol[i] == '[') {
                    answer[a_size][b_size + s_idx - i] = ']';
                }
                else {
                    answer[a_size][b_size + s_idx - i] = symbol[i];
                }
            }
            answer[a_size][b_size + s_idx + 1] = ' ';
            for (int i = 0; i <= n_idx; ++i) {
                answer[a_size][b_size + s_idx + 1 + i + 1] = name[i];
            }
            answer[a_size][b_size + s_idx + 1 + n_idx + 1 + 1] = ';';
            n_idx = -1, s_idx = -1;

            ++idx;
            // cout << name << ", " << symbol << '\n';
        }
    }
    for (int i = 0; i <= a_size; ++i) {
        int j = 0;
        while (answer[i][j] != ';') {
            cout << answer[i][j++];
        }
        cout << ';' << '\n';
    }
}

int main()
{
    cin.getline(text, 130);
    while (text[t_size] != '\0') {
        ++t_size;
    }

    solve();
}