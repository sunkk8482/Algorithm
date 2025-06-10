#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M;

int arr[16][16];
int drug[16][16];
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dx[9] = { 0,1,1,0,-1,-1,-1,0,1 };



struct node {
	int y;
	int x;
};


vector<node> vDrug;

void grow(node now) {
	for (int i = 2; i <= 8; i += 2) {
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];
		if (ny<1 || nx<1 || ny>N || nx>N)continue;
		if (arr[ny][nx] < 1)continue;
		arr[now.y][now.x]++;
	}
}

node move(node now, int d, int p) {
	for (int i = 0; i < p; i++) {
		now.y += dy[d];
		now.x += dx[d];
		if (now.y == 0)now.y = N;
		if (now.x == 0)now.x = N;
		if (now.y == N + 1)now.y = 1;
		if (now.x == N + 1)now.x = 1;
	}
	return now;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	vDrug.push_back({ N,2 });
	vDrug.push_back({ N,1 });
	vDrug.push_back({ N-1,2 });
	vDrug.push_back({ N-1,1 });
	drug[N][2] = 1;
	drug[N][1] = 1;
	drug[N - 1][1] = 1;
	drug[N - 1][2] = 1;
	for (int i = 0; i < M; i++) {
		int d, p;
		cin >> d >> p;
		// 이동
		for (int j = 0; j < vDrug.size(); j++) {
			drug[vDrug[j].y][vDrug[j].x] = 0;
			vDrug[j] = move(vDrug[j], d, p);
			drug[vDrug[j].y][vDrug[j].x] = 1;
		}

		for (auto j : vDrug) {
			drug[j.y][j.x] = 1;
		}
		// 영양제로 성장
		for (int j = 0; j < vDrug.size(); j++) {
			arr[vDrug[j].y][vDrug[j].x]++;
		}
		for (int j = 0; j < vDrug.size(); j++) {
			grow(vDrug[j]);
		}
		vDrug.clear();
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][k] >= 2) {
					if (drug[j][k])continue;
					arr[j][k] -= 2;
					vDrug.push_back({ j,k });
				}
			}
		}
		fill(drug[0], drug[16], 0);
		
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += arr[i][j];
		}
	}
	cout << answer;
}



/*

리브로수 키우려면 특수 영양제 필요
초기 특수 영양제 N*N의 좌 하단 4개의 칸에 주어짐

각각의 영양제는 1번부터 8번까지의 방향으로 
이동 칸 수만큼 이동

격자 밖이면 다시 돌아옴


순서
1. 이동 규칙에 따라 이동
2. 해당 땅에 영양제 투입 후 사라짐
3. 투입한 리브로수의 대각선으로 인접한 방향에 
격자 안 높이가 1 이상인 리브로수가 있는 만큼 높이가 더 성장
4. 특수영양제 투입한 리브로수 제외 2이상인 리브로수는 2를 베어
해당위치에 특수영양제 올림
*/