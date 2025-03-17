#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

char arr[5][5];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int visited[5][5];
int answer;

struct node {
	int y;
	int x;
};

int bfs_visited[5][5];

void bfs() {

	fill(bfs_visited[0], bfs_visited[5], 0);
	int full_cnt = 1;
	int y_cnt = 0;
	int s_cnt = 0;
	queue<node> q;
	bool find = false;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (visited[i][j]) {
				q.push({ i,j });
				bfs_visited[i][j] = 1;
				if (arr[i][j] == 'Y')y_cnt++;
				if (arr[i][j] == 'S')s_cnt++;
				find = true;
				break;
			}
		}
		if (find)break;
	}
	if (visited[0][4] && visited[2][4]&&visited[4][4]&&visited[4][2]&&visited[1][4]&&visited[4][3]) {
		int a = -1;
	}
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)continue;
			if (!visited[ny][nx])continue;
			if (bfs_visited[ny][nx])continue;
			if (arr[ny][nx] == 'Y')y_cnt++;
			if (arr[ny][nx] == 'S')s_cnt++;
			full_cnt++;
			q.push({ ny,nx });
			bfs_visited[ny][nx] = 1;
		}
	}
	
	if (full_cnt == 7) {
		if (s_cnt >= 4) {
			answer++;
		}
	}

}

void comb(int idx, int cnt) {
	if (cnt == 7) {
		bfs();
		return;
	}

	for (int i = idx; i < 25; i++) {
		*(*visited + i) = 1;
		comb(i + 1, cnt + 1);
		*(*visited + i) = 0;
	}
}


int main() {
	string input;
	for (int i = 0; i < 5; i++) {
		cin >> input;
		for (int j = 0; j < 5; j++) {
			arr[i][j] = input.at(j);
		}
	}
	comb(0, 0);
	cout << answer;
}