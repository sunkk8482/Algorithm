#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int panel[41][41];

struct knight {
	int r;
	int c;
	int h;
	int w;
	int k;
};

int L, N, Q;
// L체스판 크기, N이 기사 개수, Q 명령 개수

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

vector<knight> vKnight;
vector<int> vOriginK;

bool isMove[41];
int damage[41];

struct nextPoint {
	int r;
	int c;
};
vector<nextPoint> vNextPoint;

bool checkMove(int index, int dir) {
	for (int i = 1; i <= N; i++) {
		isMove[i] = 0;
		damage[i] = 0;
		vNextPoint[i].c = vKnight[i].c;
		vNextPoint[i].r = vKnight[i].r;

	}

	queue<int> q;
	q.push(index);
	isMove[index] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int ny = vKnight[now].r + dy[dir];
		int nx = vKnight[now].c + dx[dir];
		vNextPoint[now].r = ny;
		vNextPoint[now].c = nx;

		if (ny<1 || nx<1 || ny + vKnight[now].h - 1>L || nx + vKnight[now].w - 1>L) {
			return false;
		}

		for (int i = ny; i <= ny + vKnight[now].h - 1; i++) {
			for (int j = nx; j <= nx + vKnight[now].w - 1; j++) {
				if (panel[i][j] == 1) {
					damage[now]++;
				}
				if (panel[i][j] == 2) {
					return false;
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			if (isMove[i] || vKnight[i].k <= 0)continue;
			// y 바깥
			if (vKnight[i].r > ny + vKnight[now].h - 1 || ny > vKnight[i].r + vKnight[i].h - 1)continue;
			if (vKnight[i].c > nx + vKnight[now].w - 1 || nx > vKnight[i].c + vKnight[i].w - 1)continue;
			isMove[i] = true;
			q.push(i);
		}
	}
	damage[index] = 0;
	return true;
}

void move(int index, int dir) {
	// 목숨 확인
	if (vKnight[index].k <= 0)return;
	// 이동가능확인 후 이동
	if (checkMove(index, dir)) {
		for (int i = 1; i <= N; i++) {
			vKnight[i].r = vNextPoint[i].r;
			vKnight[i].c = vNextPoint[i].c;
			vKnight[i].k -= damage[i];
		}
	}

}

int main() {
	cin >> L >> N >> Q;
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) {
			cin >> panel[i][j];
		}
	}

	vKnight = vector<knight>(N+1);
	vOriginK = vector<int>(N + 1);
	vNextPoint = vector<nextPoint>(N + 1);
	for (int i = 1; i <= N; i++) {
		int r, c, h, w, k;
		cin >> r >> c >> h >> w >> k;
		vKnight[i] = { r,c,h,w,k };
		vOriginK[i] = k;
	}

	for (int i = 0; i < Q; i++) {
		int index, dir;
		cin >> index >> dir;
		move(index, dir);
	}

	long long answer = 0;
	for (int i = 1; i <= N; i++) {
		if (vKnight[i].k > 0) {
			answer += (vOriginK[i] - vKnight[i].k);
		}
	}
	cout << answer;
}