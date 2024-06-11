#include <iostream>
#include <string>


using namespace std;


int play(int start,int end,int del,string s) {
	while (start < end) {
		if (s.at(start) == s.at(end)) {
			start++;
			end--;
		}
		else {
			if (del == 0) {
				if (play(start + 1, end, 1, s) == 0 || play(start, end - 1, 1, s) == 0) {
					return 1;
				}
				else {
					return 2;
				}
			}
			else {
				return 2;
			}
		}
	}
	return 0;
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		cout<<play(0, s.size() - 1, 0, s)<<"\n";
	}
}