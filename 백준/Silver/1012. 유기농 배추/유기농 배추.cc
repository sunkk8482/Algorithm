#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
int m[100][100];
int M, N, K;
int cnt = 0;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int visited[100][100];

struct node {
	int y;
	int x;
};
queue<node> q;

void bfs(int y, int x) {
	node now{ y,x };
	q.push(now);
	m[y][x] = cnt;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
				continue;
			}
			if (visited[ny][nx] != 0) {
				continue;
			}
			if (map[ny][nx] == 0) {
				continue;
			}
			else {
				m[ny][nx] = cnt;
			}
			node next{ ny,nx };
			q.push(next);
			visited[ny][nx] = visited[now.y][now.x] + 1;
		}
	}

 }

void program() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[y][x] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && m[i][j] == 0) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	cout << cnt << "\n";
}

void reset() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = 0;
			m[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	cnt = 0;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		program();
		reset();
	}
}