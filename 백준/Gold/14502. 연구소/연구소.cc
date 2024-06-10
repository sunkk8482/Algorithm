#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;

int answer = -1;

int map[10][10];
int copymap[10][10];

int visited[10][10];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;

int safeSection;

struct node {
	int y;
	int x;
};

void bfs() {
	queue<node> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copymap[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny >= N || nx >= M || ny < 0 || nx < 0)continue;
			if (copymap[ny][nx]!=0) {
				continue;
			}
			copymap[ny][nx] = 3;
			q.push({ ny,nx });
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copymap[i][j] == 0) {
				cnt++;
			}
			if (copymap[i][j] == 3) {
				copymap[i][j] = 0;
			}
		}
	}
	answer = max(answer, cnt);

}


void dfs(int y,int x,int level) {
	if (level == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (i < y)continue;
		for (int j = 0; j < M; j++) {
			if (i == y && j < x)continue;
			if (copymap[i][j] == 0) {
				copymap[i][j] = 1;
				dfs(i, j, level + 1);
				copymap[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			copymap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				copymap[i][j] = 1;
				dfs(i, j, 1);
				copymap[i][j] = 0;
			}
		}
	}
	
	cout << answer;


}