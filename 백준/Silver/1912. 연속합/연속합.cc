#include <iostream>
#include <algorithm>	
using namespace std;

int arr[100001];
int dp[100001];
int answer;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	answer = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		answer = max(dp[i], answer);
	}
	cout << answer;
}