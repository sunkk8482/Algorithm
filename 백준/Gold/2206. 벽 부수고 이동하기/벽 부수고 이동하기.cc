#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;

int map[1001][1001];

int visited[1001][1001][2];
//마지막이 부순 회수

struct node {
	int y;
	int x;
	int crush;
	int cnt;
};

int answer = -1;

void func() {
	node start = { 0,0,0,1 };
	queue<node> q;
	q.push(start);
	visited[0][0][0] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.y == N - 1 && now.x == M - 1) {
			answer = now.cnt;
			return;
		}
		for (int i = 0; i < 4; i++) {
			//갈 수 있음 근데 한 번도 안부숨
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || nx >= M || ny >= N)continue;
			if (map[ny][nx] == 1) {
				if (now.crush == 0) {
					// 다음이 막혀있음 근데 벽아직 안부수고 옴
					visited[ny][nx][1] = 1;
					q.push({ ny,nx,1,now.cnt + 1 });
				}
			}
			else if (map[ny][nx] == 0) {
				if (now.crush == 0) {
					//다음 뚫림 나 벽 안부수고 옴
					if (visited[ny][nx][0]) {
						//이미 갔던 곳임
						continue;
					}
					q.push({ ny,nx,0,now.cnt + 1 });
					visited[ny][nx][0] = 1;
				}
				else if (now.crush == 1) {
					//다음 뚫림 근데 벽 부수고 옴
					if (visited[ny][nx][1]) {
						//이미 갔던 곳임
						continue;
					}
					q.push({ ny,nx,1,now.cnt + 1 });
					visited[ny][nx][1] = 1;
				}
			}

		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s.at(j) - '0';
		}
	}
	func();
	cout << answer;
}