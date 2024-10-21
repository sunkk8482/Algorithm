#include <iostream>

using namespace std;

long long zero[100];
long long one[100];

int main() {
	int n;
	cin >> n;
	zero[1] = 0;
	one[1] = 1;
	for (int i = 2; i <= n; i++) {
		long long prev_zero = zero[i - 1];
		long long prev_one = one[i - 1];
		zero[i] += prev_zero + prev_one;
		one[i] += prev_zero;
	}
	cout << zero[n] + one[n];
}