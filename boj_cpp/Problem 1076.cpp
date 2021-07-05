#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[10][2] = {
	{0, 1},
	{1, 10},
	{2, 100},
	{3, 1000},
	{4, 10000},
	{5, 100000},
	{6, 1000000},
	{7, 10000000},
	{8, 100000000},
	{9, 1000000000}
};

int main()
{
	long long answer = 0;

	vector<string> str(3);
	cin >> str[0] >> str[1] >> str[2];

	for (int i = 0; i < 3; i++) {
		if (str[i] == "black") {
			if (i == 0) {
				answer = arr[0][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[0][0];
			}
			else {
				answer *= arr[0][1];
			}
		}
		else if (str[i] == "brown") {
			if (i == 0) {
				answer = arr[1][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[1][0];
			}
			else {
				answer *= arr[1][1];
			}
		}
		else if (str[i] == "red") {
			if (i == 0) {
				answer = arr[2][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[2][0];
			}
			else {
				answer *= arr[2][1];
			}
		}
		else if (str[i] == "orange") {
			if (i == 0) {
				answer = arr[3][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[3][0];
			}
			else {
				answer *= arr[3][1];
			}
		}
		else if (str[i] == "yellow") {
			if (i == 0) {
				answer = arr[4][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[4][0];
			}
			else {
				answer *= arr[4][1];
			}
		}
		else if (str[i] == "green") {
			if (i == 0) {
				answer = arr[5][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[5][0];
			}
			else {
				answer *= arr[5][1];
			}
		}
		else if (str[i] == "blue") {
			if (i == 0) {
				answer = arr[6][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[6][0];
			}
			else {
				answer *= arr[6][1];
			}
		}
		else if (str[i] == "violet") {
			if (i == 0) {
				answer = arr[7][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[7][0];
			}
			else {
				answer *= arr[7][1];
			}
		}
		else if (str[i] == "grey") {
			if (i == 0) {
				answer = arr[8][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[8][0];
			}
			else {
				answer *= arr[8][1];
			}
		}
		else if (str[i] == "white") {
			if (i == 0) {
				answer = arr[9][0];
			}
			else if (i == 1) {
				answer *= 10;
				answer += arr[9][0];
			}
			else {
				answer *= arr[9][1];
			}
		}
	}

	cout << answer << endl;

	return 0;
}
