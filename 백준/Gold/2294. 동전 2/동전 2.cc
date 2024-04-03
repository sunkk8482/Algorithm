#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int dp[10001];

vector<int> v;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i <= 10000; i++) {
		dp[i] = 2134567890;
	}

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - v[i] >= 0) {
				dp[j] = min(dp[j - v[i]]+1, dp[j]);
			}
		}
	}
	if (dp[k] == 2134567890) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
}

/*
	1 2 3 4 5 6 7 8 9 10 11 12 13 14
	
	
	1 2 3 4 1 2 3 4 5 2 3 4 5 6 3 4 

	1 2 3 4 1 2 3 4 5 2 3 1 

	dp[10] = dp[5] + 1

	dp[16] = dp[11] + 1




*/