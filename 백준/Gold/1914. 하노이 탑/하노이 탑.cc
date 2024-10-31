#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void hanoi(int n, int from, int tmp, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
	}	
	else {
		hanoi(n - 1, from, to, tmp);
		cout << from << " " << to << "\n";
		hanoi(n - 1, tmp, from, to);
	}
}

int main() {
	int n;
	cin >> n;
	string s = to_string(pow(2, n));
	int idx = s.find(".");
	s = s.substr(0, idx);
	s[s.length() - 1] -= 1;
	cout << s <<"\n";
	if (n > 20) {
		return 0;
	}
	hanoi(n, 1, 2, 3);

}