#include <iostream>

using namespace std;

int dp[2001][2001];

int arr[2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
			}
		}
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}



}

/*

	dp[i][j] -> i부터 j까지의 여부

	arr[i] == arr[i+1] 이어도 맞음

	하나씩 늘려가기


*/