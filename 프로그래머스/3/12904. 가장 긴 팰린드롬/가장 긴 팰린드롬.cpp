#include <iostream>
#include <string>
using namespace std;

char dp[2501][2501];

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < s.size()-1; i++) {
        if (s.at(i) == s.at(i + 1)) {
            dp[i][i + 1] = 1;
        }
    }
    for (int i = 1; i < s.size(); i++) {
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s.at(i) == s.at(j) && (dp[i + 1][j - 1]||dp[j+1][i-1])) {
                dp[i][j] = 1;
                dp[j][i] = 1;
            }
        }
    }

    int size = s.size();
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= i; j--) {
            if (dp[i][j]) {
                if (answer < (j - i)) {
                    answer = j - i;
                }
            }
        }
    }
    return answer+1;
}
