#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

int arr[100];

int map[10][10];

int N, M;

int new_map[10][10];

struct node {
	int a, b;
	int price;
};

vector<node> line;
bool compare(node a, node b) {
	return a.price < b.price;
}

void init() {
	for (int i = 0; i < 100; i++) {
		arr[i] = i;
	}
}

int find(int tar) {
	if (arr[tar] == tar)return tar;
	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	arr[t2] = t1;
}

struct yx {
	int y;
	int x;
};

int visited[10][10];

void init_visited() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			visited[i][j] = 0;
		}
	}
}

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int islandCnt = 1;

struct point {
	int y;
	int x;
	int islandNumber;
};

vector<point> v;

void fun(int y, int x) {
	queue<yx> q;
	q.push({ y,x });
	visited[y][x] = 1;
	new_map[y][x] = islandCnt;
	v.push_back({ y,x,islandCnt });
	while (!q.empty()) {
		yx now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			if (visited[ny][nx])continue;
			if (map[ny][nx] == 0)continue;
			visited[ny][nx] = 1;
			new_map[ny][nx] = islandCnt;
			v.push_back({ ny,nx,islandCnt });
			q.push({ ny,nx });
		}
	}
}

void cal(point now) {
	int finishcnt = 0;
	int finished[4] = { 0,0,0,0 };

	//위
	int y = now.y;
	int x = now.x;
	int cnt = 0;
	while (true) {
		y += dy[0];
		x += dx[0];
		if (y < 0 || new_map[y][x] == now.islandNumber)break;
		if (new_map[y][x] != 0 && new_map[y][x] != now.islandNumber) {
			if (cnt > 1) {
				line.push_back({ now.islandNumber,new_map[y][x],cnt });
			}
			break;
		}
		cnt++;
	}
	//아래
	y = now.y;
	x = now.x;
	cnt = 0;
	while (true) {
		y += dy[1];
		x += dx[1];
		if (y >= N || new_map[y][x] == now.islandNumber)break;
		if (new_map[y][x] != 0 && new_map[y][x] != now.islandNumber) {
			if (cnt > 1) {
				line.push_back({ now.islandNumber,new_map[y][x],cnt });
			}
			break;
		}
		cnt++;
	}
	//좌
	y = now.y;
	x = now.x;
	cnt = 0;
	while (true) {
		y += dy[2];
		x += dx[2];
		if (x < 0 || new_map[y][x] == now.islandNumber)break;
		if (new_map[y][x] != 0 && new_map[y][x] != now.islandNumber) {
			if (cnt > 1) {
				line.push_back({ now.islandNumber,new_map[y][x],cnt });
			}
			break;
		}
		cnt++;
	}
	//우
	y = now.y;
	x = now.x;
	cnt = 0;
	while (true) {
		y += dy[3];
		x += dx[3];
		if (x >= M || new_map[y][x] == now.islandNumber)break;
		if (new_map[y][x] != 0 && new_map[y][x] != now.islandNumber) {
			if (cnt > 1) {
				line.push_back({ now.islandNumber,new_map[y][x],cnt });
			}
			break;
		}
		cnt++;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && new_map[i][j] == 0) {
				fun(i, j);
				islandCnt++;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cal(v[i]);
	}

	sort(line.begin(), line.end(), compare);

	init();
	int target = islandCnt - 2;
	int selectCount = 0;
	int result = 0;
	bool finish = false;
	for (auto i : line) {
		if (find(i.a) == find(i.b))continue;
		setUnion(i.a, i.b);
		result += i.price;
		selectCount += 1;
		if (selectCount == target)
		{
			finish = true;
			break;
		}
	}

	if (finish) {
		cout << result << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;

}