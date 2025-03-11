#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dist[101][101];

int arr[101][101];
int N;

int visited[101][101];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt;
};

int landCnt = 2;

void bfs1(int y, int x) {
	fill(visited[0], visited[101], 0);
	queue<node> q;
	q.push({ y,x,0 });
	visited[y][x] = 1;
	arr[y][x] = landCnt;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || nx >= N || ny >= N)continue;
			if (arr[ny][nx] == 0)continue;
			if (visited[ny][nx] == 1)continue;
			arr[ny][nx] = landCnt;
			visited[ny][nx] = 1;
			q.push({ ny,nx,now.cnt + 1 });
		}
	}
}

void bfs2(int y, int x) {
	fill(visited[0], visited[101], 0);
	queue<node> q;
	q.push({ y,x,0 });
	visited[y][x] = 1;
	int myLand = arr[y][x];
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || nx >= N || ny >= N)continue;
			if (arr[ny][nx] != 0 ) {
				if (arr[ny][nx] == myLand)continue;
				dist[y][x] = now.cnt;
				return;
			}
			if (visited[ny][nx] == 1)continue;
			visited[ny][nx] = 1;
			q.push({ ny,nx,now.cnt + 1 });
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				bfs1(i, j);
				landCnt++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(arr[i][j]!=0)
			bfs2(i, j);
		}
	}
	int ans = 2134567890;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] != 0) {
				ans = min(ans, dist[i][j]);
			}
		}
	}
	cout << ans;

}