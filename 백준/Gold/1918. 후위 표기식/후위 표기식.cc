#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

stack<char> st;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		char now = s.at(i);
		if (now >= 'A' && now <= 'Z') {
			cout << now;
		}
		else {
			if (now == '('||st.empty()) {
				st.push(now);
			}
			else if (now == '+' || now == '-' || now == '*' || now == '/') {
				if (st.top() == '(') {
					st.push(now);
				}
				else if ((now == '*' || now == '/')&&(st.top()=='-'||st.top()=='+')) {
					st.push(now);
				}
				else {
					while (!((now == '*' || now == '/') && (st.top() == '-' || st.top() == '+'))) {
						cout << st.top();
						st.pop();
						if (st.empty()||st.top()=='(') {
							break;
						}
					}
					st.push(now);
					
				}
			}
			else if (now == ')') {
				while (st.top()!='(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}