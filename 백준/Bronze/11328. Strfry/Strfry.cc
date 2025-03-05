#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

int dat[26];
bool pos;
int main() {
	cin >> N;
	string s1, s2;

	while (N--) {
		cin >> s1 >> s2;
		fill(dat, dat + 26, 0);
		pos = true;
		for (int i = 0;i < s1.length();i++) {
			dat[s1[i] - 'a']++;
			dat[s2[i] - 'a']--;
		}

		for (int i = 0;i < 26;i++) {
			if (dat[i] != 0) {
				pos = false;
				break;
			}
		}
		if (pos) {
			cout << "Possible\n";
		}
		else {
			cout << "Impossible\n";
		}
	}
}