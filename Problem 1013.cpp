#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check = true;
string answer = "";

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string signal;
		cin >> signal;

		answer = "";
		int x = 0;
		check = true;
		while (x < signal.size()) {
			if (signal[x] == '0') {	// case 2
				if (x + 1 < signal.size() && signal[x + 1] == '1')
					x += 2;
				else {
					answer = "NO";
					break;
				}
			}
			else {	// case 1
				if (x + 2 < signal.size() && signal[x + 1] == '0' && signal[x + 2] == '0') {
					x += 2;
					while (signal[x] == '0')
						x++;
					if (x == signal.size()) {
						answer = "NO";
						break;
					}
					int count_1 = 0;
					while (signal[x] == '1') {
						count_1++;
						if (x == signal.size() - 1) {
							answer = "YES";
							x++;
							break;
						}
						else {
							if (signal[x + 1] == '1')
								x++;
							else {
								if (x + 2 < signal.size() && signal[x + 2] == '0') {
									if (count_1 == 1) {
										answer = "NO";
										check = false;
										break;
									}
									else break;
								}
								else {
									x++;
									break;
								}
							}
						}
					}
					if (!check) break;
				}
				else {
					answer = "NO";
					check = false;
					break;
				}
			}
			if (x == signal.size()) {
				answer = "YES";
			}
		}
		cout << answer << endl;
	}

	return 0;
}
