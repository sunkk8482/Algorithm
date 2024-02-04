#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;

char map[600][600];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
};

int dist[600][600];

queue<node> q;

int answer = 0;

void fun(int y, int x) {
	dist[y][x] = 1;
	node input{ y,x };
	q.push(input);

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny >= N || ny < 0 || nx < 0 || nx >= M) {
				continue;
			}
			if (map[ny][nx] == 'X') {
				continue;
			}
			if (dist[ny][nx] != 0) {
				continue;
			}
			if (map[ny][nx] == 'P') {
				answer++;
			}
			node next{ ny,nx };
			q.push(next);
			dist[ny][nx] = dist[now.y][now.x] + 1;
		}

	}


}

int main() {
	cin >> N >> M;
	int starty;
	int startx;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s.at(j);
			if (map[i][j] == 'I') {
				starty = i;
				startx = j;
			}
		}
	}
	fun(starty, startx);
	if (answer == 0) {
		cout << "TT";
		return 0;
	}
	cout << answer;
	
}