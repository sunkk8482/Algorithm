#include <iostream>
#include <queue>
#include<math.h>
#include <algorithm>
using namespace std;

char arr[26][26];
int visited[26][26];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int n, m;

int full_cnt;

struct node {
	int y;
	int x;
};

struct calc_node {
	int y;
	int x;
	int ori;
};

struct answer {
	int y;
	int x;
	string ans;
	char ori;
};

bool avail(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) {
		return false;
	}
	return true;
}

answer calc(node start) {
	int visited2[26][26];
	fill(visited2[0], visited2[26], 0);
	int cnt = 1;
	string ret = "";

	int dir;
	char orientation = '^';

	for (int i = 0; i < 4; ++i) {
		int ny = start.y + dy[i];
		int nx = start.x + dx[i];
		if (ny<0||nx<0||ny>=n||nx>=m) continue;
		if (arr[ny][nx] == '#') {
			dir = i;
			orientation = "^>v<"[i];
			break;
		}
	}

	queue<calc_node> q;
	q.push({ start.y, start.x, dir });
	visited2[start.y][start.x] = true;

	while (!q.empty()) {
		calc_node now = q.front();
		q.pop();

		int ny1 = now.y + dy[now.ori];
		int nx1 = now.x + dx[now.ori];
		int ny2 = now.y + (dy[now.ori] * 2);
		int nx2 = now.x + (dx[now.ori] * 2);

		if (avail(ny1,nx1) &&
			avail(ny2,nx2) &&
			arr[ny1][nx1] == '#' && arr[ny2][nx2] == '#' &&
			!visited2[ny1][nx1] && !visited2[ny2][nx2]) {
			ret += 'A';
			cnt += 2;
			visited2[ny1][nx1] = visited2[ny2][nx2] = true;
			q.push({ ny2, nx2, now.ori });
			continue;
		}

		for (int turn = -1; turn <= 1; turn += 2) {
			int nd = (now.ori + turn + 4) % 4;
			int tny1 = now.y + dy[nd];
			int tnx1 = now.x + dx[nd];
			int tny2 = now.y + (dy[nd] * 2);
			int tnx2 = now.x + (dx[nd] * 2);

			if (avail(tny1,tnx1) &&
				avail(tny2,tnx2)&&
				arr[tny1][tnx1] == '#' && arr[tny2][tnx2] == '#' &&
				!visited2[tny1][tnx1] && !visited2[tny2][tnx2]) {
				ret += (turn == -1 ? 'L' : 'R');
				ret += 'A';
				cnt += 2;
				visited2[tny1][tnx1] = visited2[tny2][tnx2] = true;
				q.push({ tny2, tnx2, nd });
				break;
			}
		}
	}

	return { start.y, start.x, ret, orientation };
}

int main(int argc, char** argv)
{
	cin >> n >> m;
	pair<int, int>start;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '#') {
				start = { i,j };
				full_cnt++;
			}
		}
	}

	queue<node> q;
	q.push({ start.first,start.second });
	visited[start.first][start.second] = 1;
	vector<node> edge_points;
	// 딱 하나만 연결된 칸 찾기
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		int link_cnt = 0;
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (arr[ny][nx] == '.')continue;
			if (visited[ny][nx]) {
				link_cnt++;
				continue;
			}
			link_cnt++;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
		if (link_cnt == 1) {
			edge_points.push_back(now);
		}
	}
	
	vector<answer> answers;
	for (auto i : edge_points) {
		answer ret = calc(i);
		answers.push_back(ret);
	}

	int min_length = 2134567890;
	for (auto i : answers) {
		
		min_length = min(min_length, (int)i.ans.length());
	}
	vector<answer> fin_answers;
	for (auto i : answers) {
		if (i.ans.length() == min_length) {
			fin_answers.push_back(i);
		}
	}
	answer aaa = fin_answers[0];
	cout << aaa.y+1 << " " << aaa.x+1 << "\n";
	cout << aaa.ori << "\n";
	cout << aaa.ans;
	return 0;
}