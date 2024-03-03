#include <iostream>
#include <algorithm>

using namespace std;

int dp[1002][3];

int main() {
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + b;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + c;
	}

	cout << min(dp[N][2],min(dp[N][0], dp[N][1]));
}