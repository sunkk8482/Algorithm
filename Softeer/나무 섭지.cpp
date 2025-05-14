#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int n, m;

char arr[1001][1001];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt;
};

int visited[1001][1001];
int ghostTime[1001][1001];

void ghostBFS(vector<pair<int, int>>& ghosts) {
	queue<node> q;
	for (auto g : ghosts) {
		q.push({ g.first, g.second, 0 });
		ghostTime[g.first][g.second] = 0;
	}

	while (!q.empty()) { 
		node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			int ncnt = now.cnt + 1;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (ghostTime[ny][nx] <= ncnt) continue;
			q.push({ ny, nx, ncnt });
			ghostTime[ny][nx] = ncnt;
		}
	}
}
int main(int argc, char** argv)
{
	cin >> n >> m;
	int min_ghost = 2134567890;
	vector<pair<int, int>> ghosts;
	pair<int, int> start;
	pair<int, int> goal;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'G') {
				ghosts.push_back({ i,j });
			}
			if (arr[i][j] == 'N') {
				start = { i,j };
			}
			if (arr[i][j] == 'D') {
				goal = { i,j };
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ghostTime[i][j] = 1e9;

	ghostBFS(ghosts);
	queue<node> q;
	bool answer = false;
	q.push({ start.first,start.second,0 });
	visited[start.first][start.second] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (arr[now.y][now.x] == 'D') {
			answer = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			int ncnt = now.cnt + 1;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (arr[ny][nx] == '#')continue;
			if (visited[ny][nx])continue;
			if (ncnt >= ghostTime[ny][nx])continue;
			q.push({ ny,nx,ncnt });
			visited[ny][nx] = 1;
		}
	}
	if (answer) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}



	return 0;
}

/*

벽 출구 남우 유령
남우 1초에 한번씩 벽 제외 상하좌우

유령 1초에 한번씩 어디든 상하좌우 or 가만히 있음

*/