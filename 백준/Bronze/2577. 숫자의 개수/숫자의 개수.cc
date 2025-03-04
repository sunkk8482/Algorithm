#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	int result = a * b * c;
	vector<int>dat(10);
	while (result != 0) {
		dat[result % 10]++;
		result /= 10;
	}
	for (auto i : dat) {
		cout << i << "\n";
	}
}