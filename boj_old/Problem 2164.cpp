#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1) {
		cout << n << endl;
		return 0;
	}

	deque<int> deq;
	for (int i = 0; i < n; i++) {
		deq.push_back(i + 1);
	}
	 
	while (deq.size() != 0) {
		deq.pop_front();
		if (deq.size() == 1) {
			cout << deq[0] << endl;
			break;
		}
		deq.push_back(deq[0]);
		deq.pop_front();
	}

	return 0;
}
