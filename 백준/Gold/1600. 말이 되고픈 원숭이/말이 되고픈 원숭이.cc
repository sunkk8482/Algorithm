#include <iostream>
#include <queue>

using namespace std;

int K;
int arr[201][201];
int visited[31][201][201];
int W, H;

int dcy[8] = { -1,-2,-2,-1,1,2,2,1 };
int dcx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt;
	int ans;
};

int main() {
	cin >> K >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}
	if (W == 1 && H == 1) {
		cout << 0;
		return 0;
	}
	queue<node> q;
	q.push({ 0,0,0,0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W)continue;
			if (visited[now.cnt][ny][nx])continue;
			if (arr[ny][nx])continue;
			if (ny == H - 1 && nx == W - 1) {
				cout << now.ans + 1;
				return 0;
			}
			q.push({ ny,nx,now.cnt,now.ans+1 });
			visited[now.cnt][ny][nx] = 1;
		}
		if (now.cnt <K) {
			for (int i = 0; i < 8; i++) {
				int ny = now.y + dcy[i];
				int nx = now.x + dcx[i];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W)continue;
				if (visited[now.cnt+1][ny][nx])continue;
				if (arr[ny][nx])continue;
				if (ny == H - 1 && nx == W - 1) {
					cout << now.ans + 1;
					return 0;
				}
				q.push({ ny,nx,now.cnt+1,now.ans+1 });
				visited[now.cnt + 1][ny][nx] = 1;
			}
		}
	}
	cout << -1;


}