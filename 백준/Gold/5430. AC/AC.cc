#include <iostream>
#include <deque>
#include <string>

using namespace std;

int T;

deque<int> deq;

void extract(string s) {
	bool number = false;
	int result = 0;
	for (auto i : s) {
		if (i <= '9' && i >= '0') {
			if (number == false) {
				result += i - '0';
				number = true;
			}
			else {
				result *= 10;
				result += i - '0';
			}
		}
		else {
			if (number) {
				deq.push_back(result);
				result = 0;
				number = false;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;
	string s;
	int n;
	string arr;
	while (T--) {
		deq.clear();
		bool reverse = false;
		bool error = false;
		cin >> s;
		cin >> n;
		cin >> arr;
		extract(arr);
		for (auto i : s) {
			if (i == 'R') {
				reverse = !reverse;
			}
			else if (i == 'D') {
				if (deq.empty()) {
					error = true;
					break;
				}
				if (reverse) {
					deq.pop_back();
				}
				else {
					deq.pop_front();
				}
			}
		}
		if (error) {
			cout << "error\n";
			continue;
		}
		if (reverse) {
			cout << "[";
			for (int i = deq.size() - 1;i >= 0;i--) {
				cout << deq[i];
				if (i != 0) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
		else {
			cout << "[";
			for (int i = 0;i < deq.size();i++) {
				cout << deq[i];
				if (i != deq.size()-1) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
		

}