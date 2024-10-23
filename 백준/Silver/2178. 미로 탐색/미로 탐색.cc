#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int visited[101][101];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt;
};

int arr[101][101];

queue<node>  q;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			
				arr[i][j] = s.at(j) - '0';
			
		}
	}

	node init = { 0,0,0 };
	q.push(init);

	int answer = 2134567890;

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.y == n - 1 && now.x == m - 1) {
			answer = min(answer, now.cnt);
		}
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (visited[ny][nx] == 1)continue;
			if (arr[ny][nx] == 0)continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx,now.cnt + 1 });
		}
	}

	cout << answer+1;

	
}