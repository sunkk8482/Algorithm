#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int arr[501][501];

int visited[501][501];

int answer = 0;

void dfs(int y,int x,int sum,int level) {
	if (level == 3) {
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
		if (visited[ny][nx])continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, sum + arr[ny][nx], level + 1);
		visited[ny][nx] = 0;
	}
}

int t(int y,int x) {
	int sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2];
	int down = -1;
	int up = -1;
	if (y == 0) {
		down = arr[y + 1][x + 1];
	}
	else if (y == N - 1) {
		up = arr[y - 1][x + 1];
	}
	else {
		down = arr[y + 1][x + 1];
		up = arr[y - 1][x + 1];
	}
	sum += max(down, up);
	return sum;
}

int t2(int y, int x) {
	int sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x];
	int left = -1;
	int right = -1;
	if (x == 0) {
		right = arr[y + 1][x + 1];
	}
	else if (x == M - 1) {
		left = arr[y + 1][x - 1];
	}
	else {
		left = arr[y + 1][x - 1];
		right = arr[y + 1][x + 1];
	}
	sum += max(left, right);
	return sum;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			dfs(i, j, arr[i][j], 0);
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M-2; j++) {
			answer = max(answer, t(i, j));
		}
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M ; j++) {
			answer = max(answer, t2(i, j));
		}
	}

	cout << answer;

}