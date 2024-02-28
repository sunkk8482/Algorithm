#include <iostream>
#include <vector>

using namespace std;

int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };

struct node {
	bool die;
	int y;
	int x;
	int dir;
	int num;
};
vector<node> v;
vector<int> people[100][100];

int N, M, K;

void move() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].die)continue;
		node now = v[i];
		
		int ny = now.y + dy[now.dir];
		int nx = now.x + dx[now.dir];

		v[i].x = nx;
		v[i].y = ny;

		if (ny == 0 || ny == N - 1 || nx == 0 || nx == N - 1) {
			if (v[i].num == 1) {
				v[i].die = true;
			}
			if (now.dir % 2 == 1) {
				v[i].dir += 1;
			}
			else {
				v[i].dir -= 1;
			}
			v[i].num /= 2;
		}
		
		people[ny][nx].push_back(i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;
			
			if (people[i][j].size() > 1) {
				int maxidx = people[i][j][0];
				sum += v[maxidx].num;
				for (int k = 1; k < people[i][j].size(); k++) {
					int idx = people[i][j][k];
					sum += v[idx].num;
					if (v[maxidx].num < v[idx].num) {
						maxidx = idx;
					}
				}
				for (int k = 0; k < people[i][j].size(); k++) {
					int idx = people[i][j][k];
					if (idx != maxidx) {
						v[idx].die = true;
					}
				}
				v[maxidx].num = sum;

			}
			people[i][j].clear();
		}
	}
}

void program() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int y, x, n, d;
		cin >> y >> x >> n >> d;
		v.push_back({ false,y,x,d,n });
	}
	for (int i = 0; i < M; i++) {
		move();
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].die == false) {
			sum += v[i].num;
		}
	}
	cout << sum;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << " ";
		program();
		cout << "\n";
		v.clear();
	}
}