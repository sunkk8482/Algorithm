#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, res;
struct node {
	int left;
	int right;
};
bool compare(node left, node right) {
	if (left.left < right.left)return true;
	return false;
}
vector<node> v;
int dp[200];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(),compare);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j].right < v[i].right) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}
	cout << n - res;
}