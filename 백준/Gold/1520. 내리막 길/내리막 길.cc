#include <iostream>
#include <cstring>
using namespace std;


int map[501][501];
int dp[501][501];
int N, M;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void init() {
	memset(dp, -1, 501 * 501 * 4);
}

int dfs(int y, int x) {
	if (y == N - 1 && x == M - 1) {
		return 1;
	}
	if (dp[y][x] != -1)return dp[y][x];
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
		if (map[y][x] > map[ny][nx]) {
			dp[y][x] += dfs(ny, nx);
		}
	}
	return dp[y][x];
}

int main() {
	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 0);
	cout << dp[0][0];
}