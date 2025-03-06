#include <iostream>
#include <list>
#include <string>

using namespace std;

int M;

list<char> li;

int main() {
	string s;
	cin >> s;
	for (auto i : s) {
		li.push_back(i);
	}
	cin >> M;
	auto cur = li.end();
	while (M--) {
		char in;
		cin >> in;
		if (in == 'P') {
			char add;
			cin >> add;
			li.insert(cur, add);
		}
		else if (in == 'L') {
			if(cur!=li.begin())
			cur--;
		}
		else if (in == 'D') {
			if (cur != li.end())cur++;
		}
		else if (in == 'B') {
			if (cur != li.begin()) {
				cur--;
				cur = li.erase(cur);
			}
		}
	}

	for (auto i : li) {
		cout << i;
	}
}