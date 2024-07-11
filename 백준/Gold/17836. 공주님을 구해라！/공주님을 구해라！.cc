#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int map[101][101];

int N, M, T;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int visited[101][101][2];

struct node {
	int y;
	int x;
	int knife;
	int time;
};

int answer = 2134567890;

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	queue<node> q;
	q.push({ 0,0,0,0 });

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.time > T) {
			continue;
		}
		if (now.y == N - 1 && now.x == M - 1) {
			answer = min(now.time, answer);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			int nextTime = now.time + 1;

			if (now.knife) {
				if (visited[ny][nx][1])continue;
				visited[ny][nx][1] = 1;
				q.push({ ny,nx,1,nextTime });
			}
			else {
				if (visited[ny][nx][0])continue;
				if (map[ny][nx] == 1)continue;
				visited[ny][nx][0] = 1;
				if (map[ny][nx] == 2) {
					q.push({ ny,nx,1,nextTime });
				}
				else {
					q.push({ ny,nx,0,nextTime });
				}
			}
		}
	}
	if (answer == 2134567890) {
		cout << "Fail";
		return 0;
	}
	cout << answer;
}