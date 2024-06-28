#include <iostream>
#include <queue>

using namespace std;

int N, M;

int map[101][101];

int cheeze;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int visited[101][101];

struct node {
	int y;
	int x;
};

void init() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visited[i][j] = 0;
		}
	}
}

int bfs() {
	int ret = 0;
	queue<node> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = 1;
			if (map[ny][nx] == 1) {
				map[ny][nx] = 0;
				cheeze--;
				ret++;
			}
			else {
				q.push({ ny,nx });
			}
		}
	}
	return ret;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				cheeze++;
			}
		}
	}
	int result = 0;
	int time = 0;
	while (cheeze != 0) {
		init();
		result = bfs();
		time++;
	}
	cout << time << "\n" << result;

}