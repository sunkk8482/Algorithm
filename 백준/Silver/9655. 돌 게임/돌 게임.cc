#include <iostream>
#include <algorithm>


using namespace std;

int main() {
	int N;          
	int dp[1000];   

	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	if (dp[N] % 2 == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	return 0;
}
