#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		if ((n + 1) % (n % 100) == 0) {
			cout << "Good\n";
		}
		else {
			cout << "Bye\n";
		}
	}
}