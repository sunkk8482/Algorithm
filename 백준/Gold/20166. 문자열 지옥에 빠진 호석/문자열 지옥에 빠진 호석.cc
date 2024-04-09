#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int N, M, K;

char arr[10][10];

int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int dx[8] = { 1,1,1,0,-1,-1,-1,0 };

unordered_map<string, int> um;

void fun(int level, int y, int x, string now) {
	if (level == 5)return;

	um[now]++;

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		/*
		if (y == 0 && x == 0) {
			if (i == 5) {
				nx = M - 1;
			}
			else if (i == 6) {
				nx = M - 1;
				ny = N - 1;
			}
			else if (i == 7) {
				ny = N - 1;
			}
		}
		else if (y == N - 1 && x == 0) {
			if (i == 3) {
				ny = 0;
			}
			else if (i == 4) {
				ny = 0;
				nx = M - 1;
			}
			else if (i == 5) {
				nx = M - 1;
			}
		}
		else if (x == M - 1 && y == 0) {
			if (i == 0) {
				nx = 0;
				ny = N - 1;
			}
			else if (i == 1) {
				nx = 0;
			}
			else if (i == 7) {
				ny = N - 1;
			}
		}
		else if (x == M - 1 && y == N - 1) {
			if (i == 1) {
				nx = 0;
			}
			else if (i == 2) {
				nx = 0;
				ny = 0;
			}
			else if (i == 3) {
				ny = 0;
			}
		}

		*/

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
			if (ny == -1) {
				ny = N - 1;
			}

			if (nx == -1) {
				nx = M - 1;
			}
			if (nx == M) {
				nx = 0;
			}
			if (ny == N) {
				ny = 0;
			}
		}
		string next;
		next = now + arr[ny][nx];

		fun(level + 1, ny, nx, next);

	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s.at(j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			string s = "";
			s += arr[i][j];
			fun(0, i, j, s);
		}
	}

	for (int i = 0; i < K; i++) {
		string s;
		cin >> s;
		cout << um[s] << "\n";
	}

}