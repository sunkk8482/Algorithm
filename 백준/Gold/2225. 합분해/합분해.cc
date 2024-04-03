#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[201][201];
// dp[n][k] n을 k개로 만드는 경우의 수

// n개를 k개로 만드는 경우의 수 반환
long long fun(int n,int k) {
	if (dp[n][k] != 0)return dp[n][k];
	if (n == 0) {
		dp[n][k] = 1;
		return dp[n][k];
	}
	if (k == 1) {
		dp[n][k] = 1;
		return dp[n][k];
	}
	long long ret = 0;
	for (int i = 0; i <= n; i++) {
		dp[n-i][k-1] = fun(n-i,k-1) % 1000000000;;
		ret += dp[n-i][k-1];
	}
	return ret;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << fun(n, k)%1000000000;
}

/*
4 3

0 0 3
0 1 2
0 2 1
0 3 0




*/