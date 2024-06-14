#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i < s2.size(); i++) {
		char target = s2.at(i);
		for (int j = 0; j < s1.size(); j++) {
			if (target == s1.at(j)) {
				int ny = i - 1;
				int nx = j - 1;
				if (ny < 0 || nx < 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[ny][nx] + 1;
				}
			}
			else {
				int left_y = i;
				int left_x = j - 1;
				int up_y = i - 1;
				int up_x = j;
				int left = 0;
				int up = 0;
				if (left_x >= 0) {
					left = dp[left_y][left_x];
				}
				if (up_y >= 0) {
					up = dp[up_y][up_x];
				}
				dp[i][j] = max(left, up);
			}
		}
	}

	cout << dp[s2.size() - 1][s1.size() - 1];


}