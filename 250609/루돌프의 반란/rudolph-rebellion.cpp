#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// N게임판 크기, M턴, P산타, C루돌프 파워, D산타 파워
int N, M, P, C, D;

int dry[8] = { -1,1,0,0,-1,1,1,-1 };
int drx[8] = { 0,0,-1,1,1,1,-1,-1 }; 
int dsy[4] = { -1,0,1,0 };
int dsx[4] = { 0,1,0,-1 };

int panel[51][51];

struct santa {
	int r;//y 
	int c;//x
	int stunTime;//기절시간
	bool out;//탈락
	int score;//점수
};
vector<santa> vSanta;

// 루돌프 좌표(r,c)
pair<int, int> rudolph;

int getDist(int x1, int y1, int x2, int y2) {
	return pow(x1 - x2, 2) + pow(y1 - y2,2);
}

void combine(int who,int target,int dir) {
	int ny = 0;
	int nx = 0;
	if (who == 1) {
		ny = vSanta[target].r + dry[dir];
		nx = vSanta[target].c + drx[dir];
	}
	else if (who == 2) {
		ny = vSanta[target].r + dsy[dir];
		nx = vSanta[target].c + dsx[dir];
	}
	// 탈락 확인
	if (ny<1 || nx<1 || ny>N || nx>N) {
		vSanta[target].out = true;
		return;
	}
	// 누구 있는지 확인
	if (panel[ny][nx] != 0) {
		combine(who, panel[ny][nx], dir);
	}
	// 이동
	panel[vSanta[target].r][vSanta[target].c] = 0;
	panel[ny][nx] = target;
	vSanta[target].r = ny;
	vSanta[target].c = nx;
}

void crush(int who,int target,int dir) {
	// 1이면 루돌프가 한거
	// 2이면 산타가 한거
	if (who == 1) {
		vSanta[target].score += C;
		santa now = vSanta.at(target);
		int ny = (dry[dir] * C) + now.r;
		int nx = (drx[dir] * C) + now.c;
		// 탈락 확인
		if (ny<1 || nx<1 || ny>N || nx>N) {
			vSanta[target].out = true;
			panel[vSanta[target].r][vSanta[target].c] = 0;
			return;
		}
		now.r = ny;
		now.c = nx;
		// 이동 하기전 상호작용 확인
		if (panel[ny][nx] != 0) {
			combine(who,panel[ny][nx], dir);
		}
		panel[vSanta[target].r][vSanta[target].c] = 0;
		panel[ny][nx] = target;
		vSanta[target].r = ny;
		vSanta[target].c = nx;
	}
	else if (who == 2) {
		// 산타가 간거
		vSanta[target].score += D;
		int reverseDir = 0;
		if (dir == 0)reverseDir = 2;
		else if (dir == 2)reverseDir = 0;
		else if (dir == 1)reverseDir = 3;
		else if (dir == 3)reverseDir = 1;
		santa now = vSanta[target];
		int ny = (dsy[reverseDir] * D) + now.r;
		int nx = (dsx[reverseDir] * D) + now.c;
		// 탈락 확인
		if (ny<1 || nx<1 || ny>N || nx>N) {
			vSanta[target].out = true;
			panel[vSanta[target].r][vSanta[target].c] = 0;
			return;
		}
		// 이동 하기전 상호작용 확인
		if (panel[ny][nx] != 0) {
			combine(who, panel[ny][nx], reverseDir);
		}
		panel[vSanta[target].r][vSanta[target].c] = 0;
		panel[ny][nx] = target;
		vSanta[target].r = ny;
		vSanta[target].c = nx;
	}
}


void santaTurn() {
	//순서대로
	for (int i = 1; i <= P; i++) {
		if (vSanta[i].out)continue;
		// 기절 확인

		if (vSanta[i].stunTime > 0)continue;

		int mindist = 2134567890;
		int minDir = -1;
		// 현재 거리
		int nowDist = getDist(vSanta[i].c, vSanta[i].r, rudolph.second, rudolph.first);
		for (int j = 0; j < 4; j++) {
			int ny = vSanta[i].r + dsy[j];
			int nx = vSanta[i].c + dsx[j];
			// 갈수 있는지
			if (ny<1 || nx<1 || ny>N || nx>N)continue;
			if (panel[ny][nx] != 0)continue;
			// 루돌프와의 거리 계산
			int dist = getDist(rudolph.second, rudolph.first, nx, ny);
			if (dist > nowDist)continue;
			if (mindist > dist) {
				minDir = j;
				mindist = dist;
			}
		}
		if (minDir == -1) continue;
		// 이동
		panel[vSanta[i].r][vSanta[i].c] = 0;
		int y = vSanta[i].r + dsy[minDir];
		int x = vSanta[i].c + dsx[minDir];
		panel[y][x] = i;
		vSanta[i].r = y;
		vSanta[i].c = x;
		// 충돌처리
		if (y == rudolph.first && x == rudolph.second) {
			crush(2, i, minDir);
			vSanta[i].stunTime = 2;
			if (vSanta[i].out)continue;
		}
	}
	for (int i = 1; i <= P; i++) {
		if (vSanta[i].out)continue;
		vSanta[i].score++;
	}
}

void rudolphTurn() {
	//각 산타와의 거리 계산 가장 짧은거 선택
	int minSantaIdx = 1;
	int minSantaDist = 2134567890;
	int minSantaR=0;
	int minSantaC=0;
	for (int i = 1; i <= P; i++) {
		if (vSanta[i].out)continue;
		bool change = false;
		int dist = getDist(rudolph.second, rudolph.first, vSanta[i].c, vSanta[i].r);
		if (dist < minSantaDist) {
			change = true;
		}
		else if (dist == minSantaDist) {
			if (vSanta[i].r > minSantaR) {
				change = true;
			}
			else if (vSanta[i].r == minSantaR) {
				if (vSanta[i].c > minSantaC) {
					change = true;
				}
			}
		}
		if (change) {
			minSantaIdx = i;
			minSantaR = vSanta[i].r;
			minSantaC = vSanta[i].c;
			minSantaDist = dist;
		}
	}
	//이동방향 결정
	int moveDir = 0;
	int moveMinDist = 2134567890;
	for (int i = 0; i < 8; i++) {
		int ny = dry[i] + rudolph.first;
		int nx = drx[i] + rudolph.second;
		if (ny<1 || nx<1 || ny>N || nx>N)continue;
		int dist = getDist(nx, ny, vSanta[minSantaIdx].c, vSanta[minSantaIdx].r);
		if (moveMinDist > dist) {
			moveDir = i;
			moveMinDist = dist;
		}
	}
	//이동 및 충돌확인
	rudolph.first += dry[moveDir];
	rudolph.second += drx[moveDir];
	//충돌 확인
	if (panel[rudolph.first][rudolph.second]!=0) {
		int target = panel[rudolph.first][rudolph.second];
		crush(1, target,moveDir);
		vSanta[target].stunTime = 2;
	}
}

void play() {
	for (int i = 0; i <M; i++) {
		for (int j = 1; j <= P; j++) {
			if(vSanta[j].stunTime!=0)vSanta[j].stunTime--;
		}
		rudolphTurn();
		santaTurn();
	}
	// 턴 만큼 반복
	// 산타 기절시간 하나 줄이기
	// 루돌프턴
	// 산타턴
}

void calc() {
	for (int i =1;i<=P;i++) {
		cout << vSanta[i].score << " ";
	}
}

int main() {
	cin >> N >> M >> P >> C >> D;
	vSanta = vector<santa>(P + 1);
	cin >> rudolph.first >> rudolph.second;
	for (int i = 1; i <= P; i++) {
		int n, r, c;
		cin >> n >> r >> c;
		vSanta[n] = { r,c,0,false,0 };
		panel[r][c] = n;
	}
	play();
	calc();
}