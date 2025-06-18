#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int R, C;

vector<vector<int>> paper;

vector<vector<int>> sticker;

bool isPossible(int y, int x) {
	for (int i = y; i < y + R; i++) {
		for (int j = x; j < x + C; j++) {
			if (paper[i][j] == 1 && sticker[i-y][j-x]==1) {
				return false;
			}
		}
	}
	return true;
}

pair<int,int> check() {
	for (int i = 0; i < N-R+1; i++) {
		for (int j = 0; j < M-C+1; j++) {
			if (isPossible(i, j)) {
				return { i,j };
			}
		}
	}
	return { -1,-1 };
}

void rotate() {
	vector<vector<int>> temp(C, vector<int>(R, 0));
	/*
	R=2
	C=5


	
	*/
	int xIdx = R - 1;
	
	for (int i = 0; i < R; i++) {
		int yIdx = 0;
		for (int j = 0; j < C; j++) {
			temp[yIdx][xIdx] = sticker[i][j];
			yIdx++;
		}
		xIdx--;
	}
	sticker = temp;
	int t = C;
	C = R;
	R = t;
}

void attach(pair<int,int> now) {
	for (int i = now.first; i < now.first+R; i++) {
		for (int j = now.second; j < now.second+C; j++) {
			if (sticker[i-now.first][j-now.second] == 1) {
				paper[i][j] = 1;
			}
		}
	}
}

int main() {
	cin >> N >> M >> K;
	paper = vector<vector<int>>(N, vector<int>(M, 0));
	for (int query = 0; query < K; query++) {
		// 스티커 입력
		cin >> R >> C;
		sticker = vector<vector<int>>(R, vector<int>(C, 0));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> sticker[i][j];
			}
		}
		bool possible = false;
		for (int i = 0; i < 4; i++) {
			//확인
			pair<int, int> now;
			now = check();
			if (now.first != -1) {
				attach(now);
				break;
			}
			if (i == 3)break;
			//회전
			rotate();
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (paper[i][j] == 1) {
				answer++;
			}
		}
	}
	cout << answer;
}