#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int arr[16][16];
int temp_arr[16][16];
int visited[16][16];

int link[51][51];

int N, Q;

int index_num = 1;

struct field {
	int time;
	pair<int, int> start_point = { 0,0 };
	int vertical=0;
	int horizontal=0;
	int square=0;
	vector<int> shape;
	int now_square=0;
};

struct node {
	int y;
	int x;
};

int alive[20000];

unordered_map<int, field> um;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void delete_point(int num, int x, int y) {
	pair<int, int> start = um[num].start_point;
	int dy = start.second-y;
	int dx = x - start.first;
	um[num].shape[(dy* um[num].horizontal) + dx] = 0;
	um[num].now_square--;
}

void add(int x1, int y1, int x2, int y2) {
	for (int i = N - y1; i >= N - y2 + 1; i--) {
		for (int j = x1; j <= x2-1; j++) {
			if (arr[i][j] != 0) {
				int num = arr[i][j];
				delete_point(num, j, i);
			}
			arr[i][j] = index_num;
		}
	}
	um[index_num].time = index_num;
	um[index_num].start_point = { x1,y1 };
	um[index_num].vertical = y2-y1;
	um[index_num].horizontal = x2-x1;
	um[index_num].square = (y2-y1)*(x2-x1);
	um[index_num].now_square = (y2 - y1) * (x2 - x1);
	um[index_num].shape = vector<int>((y2-y1)*(x2-x1),1);
	alive[index_num] = 1;
}

bool check_separate(int num) {
	if (alive[num] == 0) return false;
	fill(visited[0], visited[16], 0);
	// num의 시작점부터 bfs 시작 넓이 비교
	
	pair<int, int>start;
	bool find = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == num) {
				start = { i,j };
				find = true;
			}
			if (find)break;
		}
		if (find)break;
	}
	queue<node>q;
	q.push({ start.first,start.second });
	visited[start.first][start.second] = 1;
	int sq = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny > N || nx > N)continue;
			if (visited[ny][nx])continue;
			if (arr[ny][nx] != num)continue;
			sq++;
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	if (sq != um[num].now_square) {
		return true;
	}
	return false;
}

void remove_field(int num) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == num) {
				arr[i][j] = 0;
			}
		}
	}
}
bool compare(field left, field right) {
	if (left.now_square > right.now_square) {
		return true;
	}
	else if (left.now_square == right.now_square) {
		if (left.time < right.time) {
			return true;
		}
	}
	return false;
}

bool check_avail(int y, int x,int num) {
	int hori = um[num].horizontal;
	int ver = um[num].vertical;
	int idx = 0;
	for (int i = y; i >= y - ver+1; i--) {
		if (i == 0)return false;;
		for (int j = x; j <= x + hori-1; j++) {
			if (j == N)return false;
			if (um[num].shape[idx]) {
				if (temp_arr[i][j] != 0) {
					return false;
				}
			}
			idx++;
		}
	}
	return true;
}

void fill_temp(int y, int x, int num) {
	int hori = um[num].horizontal;
	int ver = um[num].vertical;
	int idx = 0;
	for (int i = y; i >= y - ver+1; i--) {
		for (int j = x; j <= x + hori-1; j++) {
			if (um[num].shape[idx]) {
				temp_arr[i][j] = num;
			}
			idx++;
		}
	}
}

void copy_temp() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			arr[i][j] = temp_arr[i][j];
		}
	}
}

void check_in(int num) {
	bool finish = false;
	for (int i = 0; i <= N; i++) {
		for (int j = N; j >= 1; j--) {

			if (check_avail(j, i, num)) {
				um[num].start_point = { i,j };
				fill_temp(j, i, num);
				finish = true;
				break;
			}
		}
		if (finish)break;
	}
	if (!finish) {
		remove_field(num);
		alive[num] = 0;
	}
}

void move() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			temp_arr[i][j] = 0;
		}
	}
	vector<field> v;
	for (int i = 1; i <= index_num; i++) {
		if(alive[i])v.push_back(um[i]);
	}
	sort(v.begin(), v.end(), compare);
	for (auto i : v) {
		check_in(i.time);
	}
	copy_temp();
}
void bfs(int num) {
	fill(visited[0], visited[16], 0);
	// num의 시작점부터 bfs 시작 넓이 비교

	pair<int, int>start;
	bool find = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == num) {
				start = { i,j };
				find = true;
			}
			if (find)break;
		}
		if (find)break;
	}
	queue<node>q;
	q.push({ start.first,start.second });
	visited[start.first][start.second] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny > N || nx > N)continue;
			if (visited[ny][nx])continue;
			if (arr[ny][nx] == 0)continue;
			if (arr[ny][nx] != num ) {
				link[num][arr[ny][nx]] = 1;
				link[arr[ny][nx]][num] = 1;
				continue;
			}
			
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

int check_link() {
	fill(link[0],link[50],0);
	int ret = 0;
	for (int i = 1; i <= index_num; i++) {
		if (alive[i] == 0)continue;
		bfs(i);
	}
	for (int i = 1; i <= index_num-1; i++) {
		if (alive[i] == 0)continue;
		for (int j = i + 1; j <= index_num; j++) {
			if (link[i][j]) {
				ret += (um[i].now_square) * (um[j].now_square);
				link[i][j] = 0;
				link[j][i] = 0;
			}
		}
	}
	return ret;
}

int main() {
	cin >> N >> Q;
	for (int i = 0; i < Q; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
 		add(x1, y1, x2, y2);
		for (int j = 1; j <= index_num; j++) {
			if (check_separate(j)) {
				remove_field(j);
				alive[j] = 0;
			}
		}
		move();
		cout << check_link()<<"\n";


		index_num++;
	}
}
