#include <iostream>
#include <string>

using namespace std;

int plus;
int minus; 
int main() {
	string s;
	cin >> s;
	bool flag = true;
	int answer = 0;
	int num = 0;
	for (auto i : s) {

		if (i == '-'&&flag) {
			answer += num;
			num = 0;
			flag = false;
		}
		else if (i == '+'&&flag) {
			answer += num;
			num = 0;
		}
		else if(i<='9'&&i>='0') {
			num *= 10;
			num += i - '0';
		}
		else if (!flag) {
			answer -= num;
			num = 0;
		}
	}
	if (flag) {
		answer += num;
	}
	else {
		answer -= num;
	}
	cout << answer;
} 