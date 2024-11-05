#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis_dp[1001];
int lds_dp[1001];

vector<int> lis;
vector<int> lds;

int arr[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	lis.push_back(arr[0]);
	lis_dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[idx] = arr[i];
		}
		lis_dp[i] = lis.size();
	}
	lds.push_back(arr[n-1]);
	lds_dp[n - 1] = 1;
	for (int i = n-2; i>=0; i--) {
		if (lds.back() < arr[i]) {
			lds.push_back(arr[i]);
		}
		else {
			int idx = lower_bound(lds.begin(), lds.end(), arr[i]) - lds.begin();
			lds[idx] = arr[i];
		}
		lds_dp[i] = lds.size();
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer = max(answer, lis_dp[i] + lds_dp[i]-1);
	}
	cout << answer;
}