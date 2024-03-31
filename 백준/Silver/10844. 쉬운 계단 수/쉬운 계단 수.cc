#include <iostream>

using namespace std;

long long dp[101][11]; // 길이가 a일때 마지막 수가 b일 경우의 수


int main() {
	int n;
	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	//1개면 일단 1개
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9)dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	long long answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += dp[n][i];
	}
	cout << answer%1000000000;
}

/*
길이가 2일때 0 이면 10 한개
		1이면 01 21 두개
		2이면 12 32

		3 이면 1일때 101 121 321 
*/