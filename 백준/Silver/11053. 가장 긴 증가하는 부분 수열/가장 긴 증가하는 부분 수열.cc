#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int dp[1000000];
int arr[1000000];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > max) {
			max = dp[i];
		}
	}
	cout << max;
}