#include <iostream>
#include <queue>

using namespace std;

int N, M;

struct node {
	int y;
	int x;
	int d;
};

int arr[100][100];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


int main() {
	cin >> N >> M;
	int init_y, init_x, init_d;
	cin >> init_y >> init_x >> init_d;
	// 북 동 남 서
	
	node now = { init_y,init_x,init_d };


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int answer = 0;

	while (1) {
		//청소되었는지 확인
		if (arr[now.y][now.x] == 0) {
			// 청소
			arr[now.y][now.x] = 2;
			answer++;
		}
		bool turn = false;
		// 4칸 확인
		for (int i = 0; i < 4; i++) {
			if (arr[now.y + dy[i]][now.x + dx[i]]==0) {
				turn = true;
			}
		}

		if (!turn) {
			int next_dist = now.d;
			for (int i = 0; i < 2; i++) {
				next_dist++;
				if (next_dist == 4) {
					next_dist = 0;
				}
			}
			if (arr[now.y + dy[next_dist]][now.x + dx[next_dist]] == 1) {
				break;
			}
			else {
				now.y = now.y + dy[next_dist];
				now.x = now.x + dx[next_dist];
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				now.d--;
				if (now.d == -1)now.d = 3;
				if (arr[now.y + dy[now.d]][now.x + dx[now.d]] == 0) {
					now.y = now.y + dy[now.d];
					now.x = now.x + dx[now.d];
					break;
				}
			}
		}

	}
	cout << answer;
}