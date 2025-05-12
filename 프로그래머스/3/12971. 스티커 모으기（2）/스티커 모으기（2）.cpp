#include <vector>
#include<algorithm>
using namespace std;

int dp[100001][2];
int dp2[100001][2];
int solution(vector<int> sticker)
{
    int answer = 0;
    if(sticker.size()==1)return sticker[0];
    for (int i = 0; i < sticker.size() - 1; i++) {
        if (i == 0) {
            dp[i][0] = sticker[i];
            dp[i][1] = 0;
            continue;
        }
        dp[i][0] = dp[i - 1][1]+sticker[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    for (int i = 1; i < sticker.size(); i++) {
        if (i == 1) {
            dp2[i][0] = sticker[i];
            dp2[i][1] = 0;
            continue;
        }
        dp2[i][0] = dp2[i - 1][1] + sticker[i];
        dp2[i][1] = max(dp2[i - 1][0], dp2[i - 1][1]);
    }

    int size = sticker.size();
    answer = max(max(dp[size - 2][0], dp[size - 2][1]), max(dp2[size - 1][0], dp2[size - 1][1]));
    
    return answer;
}
