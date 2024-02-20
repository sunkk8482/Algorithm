#include <iostream>
#include <vector>
using namespace std;

vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int temp = 0;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		v.push_back(number+temp);
		temp = number+temp;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int aa = 0;
		if (a > 1) {
			aa = v[a - 2];
		}
		cout << v[b - 1] - aa<<"\n";
	}
}