#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '(') {
			st.push(s.at(i));
		}
		else {
			if (s.at(i - 1) == '(') {
				st.pop();
				cnt += st.size();
			}
			else {
				cnt += 1;
				st.pop();
			}
		}
	}
	cout << cnt;
}