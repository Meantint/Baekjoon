#include <iostream>

#define MAX 80

using namespace std;

int main()
{
	char str[MAX] = { 0 };
	int i, j, score = 0, add = 1;
	int T;

	cin >> T;

	for (i = 0; i < T; i++)
	{
		cin >> str;
		if (str[0] == 'O')
			score += add;
		for (j = 1; str[j] != '\0'; j++)
		{
			if (str[j] == 'O')
			{
				if (str[j - 1] == 'O')
				{
					add++;
					score += add;
				}
				else // str[j - 1] == 'X'
					score += add;
			}
			else    // str[j] == 'X'
				add = 1;
		}
		cout << score << endl;
		score = 0; add = 1;
	}
}
