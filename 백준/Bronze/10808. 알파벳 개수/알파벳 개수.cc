#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

	string s;
	cin >> s;
	vector<int> dat(26);
	for (int i = 0;i < s.length();i++) {
		dat[s.at(i)-'a']++;
	}
	for (auto i : dat) {
		cout << i << " ";
	}
}