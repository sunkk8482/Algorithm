#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
	stack<int> stack;
	int n;
	cin >> n;
	bool check = false;
	vector<char> vector;
	int num;
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		cin >> num;

		while (cnt <= num) {
			stack.push(cnt);
			cnt++;
			vector.push_back('+');
		}

		if (stack.top() == num) {
			stack.pop();
			vector.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

		for (auto ch : vector) {
			cout << ch << '\n';
		}
	

}
