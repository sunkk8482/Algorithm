#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N;
int Q;

char arr[51][51];

struct state {
	int r;
	int c;
	int jumpPower;
	int time;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dist[51][51][6];
vector<state> vStateGraph[51][51][6];

bool operator<(state left, state right) {
	if (left.time <= right.time) {
		return false;
	}
	return true;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= N; j++) {
			arr[i][j] = s.at(j - 1);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] != '.')continue;
			for (int power = 1; power <= 5; power++) {
				state current = { i,j,power,0 };
				// 옵션 1
				if (power < 5) {
					int nPower = power + 1;
					vStateGraph[i][j][power].push_back({ i,j,nPower,nPower * nPower });
				}
				// 옵션 2
				for (int nPower = 1; nPower < power; nPower++) {
					vStateGraph[i][j][power].push_back({ i,j,nPower,1 });
				}
				// 옵션 3
				for (int d = 0; d < 4; d++) {
					int nowy = current.r;
					int nowx = current.c;
					bool valid = true;
					for (int step = 0; step < power; step++) {
						nowy += dy[d];
						nowx += dx[d];
						if (nowy<1 || nowy>N || nowx<1 || nowx>N || arr[nowy][nowx] == '#') {
							valid = false;
							break;
						}
					}
					if (arr[nowy][nowx] != '.') {
						valid = false;
					}
					if (valid) {
						vStateGraph[i][j][power].push_back({ nowy,nowx,power,1 });
					}
				}
			}
		}
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int startY, startX, endY, endX;
		cin >> startY >> startX >> endY >> endX;
		fill(&dist[0][0][0],&dist[51][51][6], 2134567890);
		priority_queue<state> pq;
		state start = { startY,startX,1,0 };
		pq.push(start);
		int answer = 2134567890;
		while (!pq.empty()) {
			state now = pq.top();
			pq.pop();
			if (dist[now.r][now.c][now.jumpPower] < now.time) {
				continue;
			}
			if (now.r == endY && now.c == endX) {
				answer = now.time;
				break;
			}
			for (auto j : vStateGraph[now.r][now.c][now.jumpPower]) {
				if (now.time + j.time < dist[j.r][j.c][j.jumpPower]) {
					dist[j.r][j.c][j.jumpPower] = now.time + j.time;
					pq.push({ j.r,j.c,j.jumpPower,now.time + j.time });
				}
			}
		}
		if (answer == 2134567890) {
			cout << "-1\n";
		}
		else {
			cout << answer << "\n";
		}
	}
	
}