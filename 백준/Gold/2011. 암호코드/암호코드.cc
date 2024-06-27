#include <iostream>
#include <string>
using namespace std;

long long dp[10000];
int mod = 1000000;
int main() {
	string s;
	cin >> s;
	int length = s.size();
	dp[0] = 1;
	dp[1] = 1;

	if (s.at(0) == '0') {
		cout << 0;
		return 0;
	}


	for (int i = 1; i < length; i++) {
		string now = "";
		now += s.at(i - 1);
		now += s.at(i);
		int now_int = stoi(now);

		if (s.at(i) == '0') {
			if (s.at(i - 1) == '1' || s.at(i - 1) == '2') {
				dp[i + 1] = dp[i - 1];
				dp[i + 1] %= mod;
				continue;
			}
			else {
				cout << '0';
				return 0;
			}
		}

		if (now_int<=26&&s.at(i-1)!='0') {
			dp[i + 1] = dp[i] + dp[i - 1];
			dp[i + 1] %= mod;
		}
		else {
			dp[i + 1] = dp[i];
			dp[i + 1] %= mod;
		}
	}
	cout << dp[length] % mod;

}

/*
붙을 수 있으면 dp[n]=dp[n-1]+dp[n-2];

붙을 수 없으면 dp[n]=dp[n-1;

*/

/*
25114

dp[0]=1
dp[1]=1
2
--------
붙을 수 있음
2 5
25
dp[2]=dp[1]+dp[0]
---------
붙을 수 없음
2 5 1
25 1
dp[3]=dp[2]
----------




*/