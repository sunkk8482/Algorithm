#include <iostream>
#include <queue>

using namespace std;

class Board {
public:
	int arr[5][5];

public:
	Board() {
		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 5;j++) {
				arr[i][j] = 0;
			}
		}
	}

	Board* Rotate(int y, int x, int cnt) {
		Board* result = new Board();
		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 5;j++) {
				result->arr[i][j] = arr[i][j];
			}
		}

		for (int k = 0;k < cnt;k++) {
			// sy, sx를 좌측상단으로 하여 시계방향 90도 회전합니다.
			int tmp = result->arr[y + 0][x + 2];
			result->arr[y + 0][x + 2] = result->arr[y + 0][x + 0];
			result->arr[y + 0][x + 0] = result->arr[y + 2][x + 0];
			result->arr[y + 2][x + 0] = result->arr[y + 2][x + 2];
			result->arr[y + 2][x + 2] = tmp;
			tmp = result->arr[y + 1][x + 2];
			result->arr[y + 1][x + 2] = result->arr[y + 0][x + 1];
			result->arr[y + 0][x + 1] = result->arr[y + 1][x + 0];
			result->arr[y + 1][x + 0] = result->arr[y + 2][x + 1];
			result->arr[y + 2][x + 1] = tmp;
		}
		return result;
	}

	int cal_score() {
		int score = 0;
		bool visit[5][5];
		int dy[4] = { -1,1,0,0 };
		int dx[4] = { 0,0,-1,1 };
		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 5;j++) {
				visit[i][j] = false;
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
				int target = arr[i][j];
				while (!q.empty()) {
					node now = q.front();
					q.pop();
					for (int k = 0;k < 4;k++) {
						int ny = now.y + dy[k];
						int nx = now.x + dx[k];
						if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)continue;
						if (visit[ny][nx])continue;
						if (arr[ny][nx] != arr[now.y][now.x])continue;
						temp.push_back({ ny,nx });
						visit[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
				if (temp.size() >= 3) {
					score += temp.size();
					for (auto i : temp) {
						arr[i.y][i.x] = 0;
					}
				}
			}
		}
		return score;
	}

	void Fill(queue<int>* que) {
		// 열이 작고 행이 큰 우선순위로 채워줍니다.
		for (int j = 0;j < 5;j++) {
			for (int i = 5 - 1;i >= 0;i--) {
				if (arr[i][j] == 0) {
					arr[i][j] = que->front();
					que->pop();
				}
			}
		}
	}
};

int main() {
	int M, K;
	queue<int> q;
	Board* board = new Board();

	// 입력을 받습니다.
	cin >> K >> M;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> board->arr[i][j];
		}
	}
	for (int i = 0;i < M;i++) {
		int t;
		cin >> t;
		q.push(t);
	}

	// 최대 K번의 탐사과정을 거칩니다.
	while (K--) {
		int maxScore = 0;
		Board* maxScoreBoard = NULL;
		// 회전 목표에 맞는 결과를 maxScoreBoard에 저장합니다.
		// (1) 유물 1차 획득 가치를 최대화
		// (2) 회전한 각도가 가장 작은 방법을 선택
		// (3) 회전 중심 좌표의 열이 가장 작은 구간을, 그리고 열이 같다면 행이 가장 작은 구간을 선택
		for (int cnt = 1; cnt <= 3; cnt++) {
			for (int sx = 0;sx <= 5 - 3;sx++) {
				for (int sy = 0;sy <= 5 - 3;sy++) {
					Board* rotated = board->Rotate(sy, sx, cnt);
					int score = rotated->cal_score();
					if (maxScore < score) {
						maxScore = score;
						maxScoreBoard = rotated;
					}
				}
			}
		}
		// 회전을 통해 더 이상 유물을 획득할 수 없는 경우 탐사를 종료합니다.
		if (maxScoreBoard == NULL) {
			break;
		}
		board = maxScoreBoard;
		// 유물의 연쇄 획득을 위해 유물 조각을 채우고 유물을 획득하는 과정을 더이상 획득할 수 있는 유물이 없을때까지 반복합니다.
		while (true) {
			board->Fill(&q);
			int newScore = 0;
			newScore = board->cal_score();
			if (newScore == 0) break;
			maxScore += newScore;
		}

		cout << maxScore << " ";
	}

	return 0;
}