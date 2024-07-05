#include <iostream>

using namespace std;

int dp[16][16];

void init() {
	for (int i = 0; i < 16; i++) {
		dp[0][i] = i;
	}
	for (int i = 0; i < 16; i++) {
		dp[i][1] = 1;
	}
}

int func(int k, int n) {

	if (dp[k][n] != 0)return dp[k][n];
	return dp[k][n]=func(k - 1, n) + func(k, n - 1);
}

void program() {
	int k, n;//k층에 n호에는 몇 명이 살고있는지
	cin >> k >> n;
	func(k,n);
	cout << dp[k][n]<<"\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		program();
	
	}
}