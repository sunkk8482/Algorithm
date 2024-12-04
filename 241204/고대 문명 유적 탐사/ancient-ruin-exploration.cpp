#include <iostream>
#include <queue>

using namespace std;

int arr[5][5];

int K, M;

int piece[301];

int rotated[5][5];

int temp_rotated[5][5];

int max_board[5][5];

void rotate(int y, int x, int cnt) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			rotated[i][j] = arr[i][j];
		}
	}
	for (int i = 0;i < cnt;i++) {
		int tmp = rotated[y][x + 2];
		rotated[y][x + 2] = rotated[y][x];
		rotated[y][x] = rotated[y+2][x];
		rotated[y+2][x] = rotated[y+2][x+2];
		rotated[y + 2][x + 2] = tmp;
		tmp = rotated[y+1][x + 2];
		rotated[y+1][x + 2] = rotated[y][x+1];
		rotated[y][x + 1] = rotated[y+1][x];
		rotated[y+1][x ] = rotated[y+2][x+1];
		rotated[y + 2][x + 1] = tmp;
	}
}

int cal_score() {
	int score = 0;
	bool visit[5][5];
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			visit[i][j] = false;
			temp_rotated[i][j] = rotated[i][j];
		}
	}
	struct node {
		int y;
		int x;
	};


	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (visit[i][j])continue;
			vector<node> temp;
			queue<node> q;
			q.push({ i,j });
			temp.push_back({ i,j });
			visit[i][j] = true;
			int target = temp_rotated[i][j];
			while (!q.empty()) {
				node now = q.front();
				q.pop();
				for (int k = 0;k < 4;k++) {
					int ny = now.y + dy[k];
					int nx = now.x + dx[k];
					if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)continue;
					if (visit[ny][nx])continue;
					if (temp_rotated[ny][nx] != target)continue;
					temp.push_back({ ny,nx });
					visit[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
			if (temp.size() >= 3) {
				score += temp.size();
				for (auto i : temp) {
					temp_rotated[i.y][i.x] = 0;
				}
			}
		}
	}
	return score;
}
int idx = 0;

void Fill() {

	// 열이 작고 행이 큰 우선순위로 채워줍니다.
	for (int j = 0;j < 5;j++) {
		for (int i = 5 - 1;i >= 0;i--) {
			if (rotated[i][j] == 0) {
				rotated[i][j] = piece[idx];
				if (idx + 1 != M) {
					idx++;
				}
			}
		}
	}
}

int main() {
	cin >> K >> M;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0;i < M;i++) {
		cin >> piece[i];
	}

	int max_score = 0;

	while (K--) {
		int max_score = 0;
		for (int cnt = 1;cnt <= 3;cnt++) {
			for (int i = 0;i <= 2;i++) {
				for (int j = 0;j <= 2;j++) {
					rotate(i, j, cnt);
					int score = cal_score();
					if (score > max_score) {
						max_score = score;
						for (int k = 0;k < 5;k++) {
							for (int l = 0;l < 5;l++) {
								max_board[k][l] = temp_rotated[k][l];
							}
						}
					}
				}
			}
		}
		if (max_score == 0)break;
		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 5;j++) {
				rotated[i][j] = max_board[i][j];
			}
		}
		while (1) {
			Fill();
			int newScore = 0;
			newScore = cal_score();
			if (newScore == 0) break;
			max_score += newScore;
			for (int i = 0;i < 5;i++) {
				for (int j = 0;j < 5;j++) {
					rotated[i][j] = temp_rotated[i][j];
				}
			}
		}
		cout << max_score<<" ";
		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 5;j++) {
				arr[i][j] = rotated[i][j];
			}
		}
	}

}