#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 숲은 y가 2일때부터 시작
int arr[73][73];
int visited[73][73];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

// 골렘의 정보
struct golem {
	// 중앙 좌표
	int y;
	int x;
	// 출구 번호
	int exit;
	// 골렘 번호
	int num;
};

struct node {
	int y;
	int x;
};

// R - y , C - x , K 정령의 수
int R, C, K;

bool checkRight(golem now) {
	// 일단 오른쪽 확인
	int y = now.y;
	int x = now.x + 1;
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 범위 넘음
		if (ny >= R + 2 || nx < 0 || nx >= C)return false;
		// 뭔가 있음
		if (arr[ny][nx] != 0)return false;
	}
	// 그다음 아래 확인
	y++;
	for (int i = 1; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 범위 넘음
		if (ny >= R + 2 || nx < 0 || nx >= C)return false;
		// 뭔가 있음
		if (arr[ny][nx] != 0)return false;
	}
	return true;
}

void goRight(golem& now) {
	now.y++;
	now.x++;
	now.exit++;
	if (now.exit == 4)now.exit = 0;
}

bool checkLeft(golem now) {
	// 일단 왼쪽 확인
	int y = now.y;
	int x = now.x - 1;
	for (int i = 0; i < 4; i++) {
		if (i == 1)continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 범위 넘음
		if (ny >= R + 2 || nx < 0 || nx >= C)return false;
		// 뭔가 있음
		if (arr[ny][nx] != 0)return false;
	}
	// 그다음 아래 확인
	y++;
	for (int i = 0; i < 4; i++) {
		if (i == 1 || i == 0)continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 범위 넘음
		if (ny >= R + 2 || nx < 0 || nx >= C)return false;
		// 뭔가 있음
		if (arr[ny][nx] != 0)return false;
	}
	return true;
}

void goLeft(golem &now) {
	now.y++;
	now.x--;
	now.exit--;
	if (now.exit == -1)now.exit = 3;
}

bool checkDown(golem now) {
	int y = now.y + 1;
	int x = now.x;
	// 왼쪽 오른쪽 아래 확인
	for (int i = 1; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// 범위 넘음
		if (ny >= R + 2 || nx < 0 || nx >= C)return false;
		// 뭔가 있음
		if (arr[ny][nx] != 0)return false;
	}
	return true;
}

void goDown(golem& now) {
	now.y++;
}

bool checkOut(golem now) {
	// 가장 위의 좌표가 2보다 같거나 아래면 안에 있는거
	int y = now.y - 1;
	if (y >= 2)return false;
	return true;
}

void removeArr() {
	for (int i = 0; i < R + 2; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] = 0;
		}
	}
}

void draw(golem now) {
	arr[now.y][now.x] = now.num;
	for (int i = 0; i < 4; i++) {
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];
		arr[ny][nx] = now.num;
		if (i == now.exit) {
			arr[ny][nx] += 1000;
		}
	}
}

int goOut(golem now_golem) {
	fill(visited[0], visited[72], 0);
	int ret = 0;
	queue<node> q;
	q.push({ now_golem.y,now_golem.x });
	visited[now_golem.y][now_golem.x] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		ret = max(ret, now.y);
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;
			if (ny < 2 || nx < 0 || nx >= C || ny >= R + 2)continue;
			if (visited[ny][nx])continue;
			if (arr[ny][nx] == 0)continue;
			// 번호가 다름
			if (arr[ny][nx] != arr[now.y][now.x]) {
				bool me = false;
				// 나에서 나의 탈출구로 가는거
				if (arr[ny][nx] - 1000 == arr[now.y][now.x]) {
					me = true;
				}
				// 여기는 다른 쪽으로 가는거 지금 위치가 탈출구가 아니면 스킵
				if (arr[now.y][now.x] < 1001 && !me )continue;
			}
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}

	return ret;
}

int answer;
void go(golem now) {
	while (1) {
		// 남쪽으로 가능한지 확인
		if (checkDown(now)) {
			goDown(now);
			continue;
		}
		// 서쪽으로 가능한지 확인
		if (checkLeft(now)) {
			goLeft(now);
			continue;
		}
		// 동쪽으로 가능한지 확인
		if (checkRight(now)) {
			goRight(now);
			continue;
		}
		break;
	}
	// 몸이 삐져나왔는지 확인
	if (checkOut(now)) {
		// 지워버리고 리턴
		removeArr();
		return;
	}
	// 지도에 표시
	draw(now);
	// 탈출
	answer += goOut(now)-1;
}

int main() {
	cin >> R >> C >> K;
	for (int i = 0; i < K; i++) {
		int x;
		int ex;
		cin >> x >> ex;
		go({ 0,x-1,ex,i+1 });
	}
	cout<<answer;
}



/*

R행 C열의 마법의 숲 탐색

1부터 R 까지 y

북쪽을 통해서만 숲에 들어올 수 있음

K명의 정려은 각자 골렘을 타고 숲을 탐색
골렘은 십자모양 5칸 차
중앙 제외 4칸 중 한 칸은 골렘의 출구
어느 방향에서든 탈 수 있지만 출구를 통해서만 나감

i번째 골렘은 가장 북쪽에서 시작해 중앙이 c가 되도록 하는 위치에서
내려오기 시작

움직이지 못할 때까지 다음 과정 반복

1)
남쪽으로 한칸 이동

2)
남쪽으로 못가면 서쪽으로 회전하면서 내려감

3)
그래도 못가면 동쪽으로 회전하면서

*/