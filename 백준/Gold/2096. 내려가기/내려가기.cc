#include <iostream>
#include<algorithm>
using namespace std;
int n;
int arr[3]; 
int min_dp[3] = { 0 }; 
int max_dp[3] = { 0 }; 

int main() {
    cin >> n;
    int tmp0; 
    int tmp1; 
    int tmp2;
    for (int i = 1; i <= n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2]; 

        tmp0 = min_dp[0];
        tmp1 = min_dp[1];
        tmp2 = min_dp[2];

        min_dp[0] = min(tmp0, tmp1) + arr[0];
        min_dp[2] = min(tmp1, tmp2) + arr[2];
        min_dp[1] = min(min(tmp0, tmp1), tmp2) + arr[1];

        tmp0 = max_dp[0];
        tmp1 = max_dp[1];
        tmp2 = max_dp[2];

        max_dp[0] = max(tmp0, tmp1) + arr[0];
        max_dp[2] = max(tmp1, tmp2) + arr[2];
        max_dp[1] = max(max(tmp0, tmp1), tmp2) + arr[1];
    }
    cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]);
    return 0;
}