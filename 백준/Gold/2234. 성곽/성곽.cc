#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int arr[51][51];

int visited[51][51];
int visited2[51][51];


vector<int> vRooms;
vector<int> vNeighbors;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

struct node {
	int y;
	int x;
};

int index = 0;

void bfs(node start) {
	queue<node>q;
	q.push(start);
	visited[start.y][start.x] = index;
	int size = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		int around = arr[now.y][now.x];
 		for (int i = 0; i < 4; i++) {
			if ((around & 0x01) == 1) {
				around = around >> 1;
				continue;
			}
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (visited[ny][nx] != -1)
			{
				around = around >> 1;
				continue;
			}
			q.push({ ny,nx });
			visited[ny][nx] = index;
			size++;
			around = around >> 1;
		}
	}
	vRooms.push_back(size);
	index++;
}

int answer = 0;

void bfs2(node start) {
	int currentIndex = visited[start.y][start.x];
	queue<node>q;
	q.push(start);
	visited2[start.y][start.x] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (visited2[ny][nx])continue;
			if (visited[ny][nx] != currentIndex) {
				answer = max(answer, vRooms[currentIndex] + vRooms[visited[ny][nx]]);
				continue;
			}
			visited2[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	fill(visited[0], visited[51], -1);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]==-1)
			{
				bfs({ i,j });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited2[i][j]==0)
			{
				bfs2({ i,j });
			}
		}
	}
	sort(vRooms.begin(), vRooms.end());
	cout << vRooms.size() << "\n" << vRooms[vRooms.size() - 1] << "\n" << answer;

	
 }