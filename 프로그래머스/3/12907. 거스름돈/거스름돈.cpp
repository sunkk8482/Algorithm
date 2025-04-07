#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];

int solution(int n, vector<int> money) {
    dp[0] = 1;
    sort(money.begin(), money.end());
    for (int i = money[0]; i <= n; i+=money[0]) {
        dp[i]++;
    }

    for (int i = 1; i < money.size(); i++) {
        for (int j = money[i]; j <= n; j++) {
            dp[j] += dp[j-money[i]];
        }
    }
    return dp[n];
}
