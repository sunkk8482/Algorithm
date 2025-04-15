#include <string>
#include <vector>
using namespace std;
int arr[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    for (auto i : puddles) {
        arr[i[1]][i[0]] = -1;
    }
    arr[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)continue;
            if (arr[i][j] == -1)continue;
            int now = 0;
            if (i - 1 > 0 && arr[i - 1][j] != -1) {
                now += arr[i - 1][j];
            }
            if (j - 1 > 0 && arr[i][j - 1] != -1) {
                now += arr[i][j - 1];
            }
            arr[i][j] = now%1000000007;
        }
    }
    return arr[n][m];
}