#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main() {
	int n;
	cin >> n;
	int cnt=1;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		if (cnt<number) {
			st.push(number);
		}
		else if (cnt == number) {
			cnt++;
			if (!st.empty()) {
				while (st.top() == cnt) {
					st.pop();
					cnt++;
					if (st.empty()) {
						break;
					}
				}
			}
		}
		
	}
	while (!st.empty()) {
		if (st.top() == cnt) {
			cnt++;
			st.pop();
		}
		else {
			cout << "Sad";
			return 0;
		}
	}
	cout << "Nice";
}