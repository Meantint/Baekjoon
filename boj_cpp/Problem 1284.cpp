#include <iostream>
#include <string>

using namespace std;

int main()
{
	while (1) {
		int answer = 0;

		string num;
		cin >> num;
			   
		if (num == "0") {
			break;
		}
		answer += num.size() + 1;

		for (int i = 0; i < num.size(); i++) {
			if (num[i] == '1') {
				answer += 2;
			}
			else if (num[i] == '0') {
				answer += 4;
			}
			else
				answer += 3;
		}

		cout << answer << endl;
	}

	return 0;
}
