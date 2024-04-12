#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;

int map[101][101];

int dist[101][101];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cost;
	int crush;
};

bool operator<(node left, node right) {
	if (left.crush == right.crush) {
		return left.cost > right.cost;
	}
	return left.crush > right.crush;
}

void fun() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = 2134567890;
		}
	}
	priority_queue<node> pq;
	pq.push({ 0,0,0,0 });
	dist[0][0] = 0;
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if (now.y == N - 1 && now.x == M - 1) {
			cout << now.crush;
			return;
		}
		if (now.crush > dist[now.y][now.x])continue;
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			int nextdist = now.cost + 1;
			int next_crush = now.crush;
			if (map[ny][nx] == 1)next_crush++;
			if (dist[ny][nx] <= next_crush)continue;
			pq.push({ ny,nx,nextdist,next_crush });
			dist[ny][nx] = next_crush;
		}
	}
	cout << dist[N - 1][M - 1];
}


int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s.at(j) - '0';
		}
	}

	fun();
}